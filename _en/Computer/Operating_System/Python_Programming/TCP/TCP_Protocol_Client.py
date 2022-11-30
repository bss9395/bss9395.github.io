''' TCP_Protocol_Client.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: TCP Protocol Client
'''


import struct

from TCP_Protocol_Server import TCP_Protocol
import time
import threading
import socket

# private message format:
#     @user_to@message
# public message fromat:
#     #group_to#message

class Client(object):
    def _Receive(self):
        def _Handle(header_unpack, body):
            print(f'body_size={header_unpack[0]}, topic={header_unpack[1]}', flush=True)
            print(f'{body.decode("utf-8")}', end='\n', flush=True)

            if header_unpack[1] == TCP_Protocol._private_message:
                body_decode  = body.decode('utf-8')
                (head, tail) = (0, body_decode.find(TCP_Protocol._private_sign, 0))
                user_from    = body_decode[head:tail]
                (head, tail) = (tail + 1, body_decode.find(TCP_Protocol._private_sign, tail + 1))
                user_to      = body_decode[head:tail]
                message      = body_decode[tail + 1:]
                print(f'{user_from} speak to you: {message}', flush=True)
            elif header_unpack[1] == TCP_Protocol._group_message:
                body_decode = body.decode('utf-8')
                (head, tail) = (0, body_decode.find(TCP_Protocol._group_sign, 0))
                user_from = body_decode[head:tail]
                (head, tail) = (tail + 1, body_decode.find(TCP_Protocol._group_sign, tail + 1))
                group_to = body_decode[head:tail]
                message = body_decode[tail + 1:]
                print(f'{user_from} speak to all: {message}', flush=True)
            return True

        try:
            while True:
                self._tcp_protocol._Recv(self._client, _Handle)
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            self._client.close()

    def _Send(self):
        try:
            while True:
                message = input('')
                if not message or message == 'exit':
                    break
                elif message[0] == TCP_Protocol._private_sign:
                    body_send   = (self._username + message).encode('utf-8')
                    header_send = struct.pack(TCP_Protocol._header_type, len(body_send), TCP_Protocol._private_message)
                    self._client.send(header_send + body_send)
                elif message[0] == TCP_Protocol._group_sign:
                    body_send   = (self._username + message).encode('utf-8')
                    header_send = struct.pack(TCP_Protocol._header_type, len(body_send), TCP_Protocol._group_message)
                    self._client.send(header_send + body_send)
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            self._client.close()

    def __init__(self, ip, port):
        self._client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._client.connect((ip, port))
        self._tcp_protocol = TCP_Protocol()
        self._username = ""
        self._login = False

        def _Login(header_pack, body):
            if header_pack[1] == TCP_Protocol._login_successfully:
                print(f'login successfully.', flush=True)
                self._login = True
            elif header_pack[1] == TCP_Protocol._login_failed:
                print(f'login failed.', flush=True)
                self._login = False
            return None


        while True:
            self._username = input('login: ')
            body_send = self._username.encode('utf-8')
            header_send = struct.pack(TCP_Protocol._header_type, len(body_send), TCP_Protocol._login)
            self._client.send(header_send + body_send)
            self._tcp_protocol._Recv(self._client, _Login)
            if self._login == True:
                break
        threading.Thread(target=self._Send).start()
        threading.Thread(target=self._Receive).start()


if __name__ == '__main__':
    Client(TCP_Protocol._server_address, TCP_Protocol._server_port)
