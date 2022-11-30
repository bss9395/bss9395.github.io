''' UDP_Client.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: UDP Client
'''

import struct

from UDP_Server import UDP_Protocol
import socket
import threading
import time

# private message format:
#     @user_to@message
# public message fromat:
#     #group_to#message

class Client(object):
    def _Receive(self):
        try:
            while True:
                (data, address) = self._client.recvfrom(UDP_Protocol._udp_buffer_size)
                header_unpack = struct.unpack(UDP_Protocol._header_type, data[:UDP_Protocol._header_size])
                body = data[UDP_Protocol._header_size:]
                print(f'{address}', flush=True)
                print(f'body_size={header_unpack[0]}, topic={header_unpack[1]}', flush=True)
                print(f'{body.decode("utf-8")}', end='\n\n', flush=True)

                if header_unpack[1] == UDP_Protocol._private_message:
                    body_decode  = body.decode('utf-8')
                    (head, tail) = (0, body_decode.find(UDP_Protocol._private_sign, 0))
                    user_from    = body_decode[head:tail]
                    (head, tail) = (tail + 1, body_decode.find(UDP_Protocol._private_sign, tail + 1))
                    user_to      = body_decode[head:tail]
                    message      = body_decode[tail + 1:]
                    print(f'{user_from} speak to you: {message}', flush=True)
                elif header_unpack[1] == UDP_Protocol._group_message:
                    body_decode = body.decode('utf-8')
                    (head, tail) = (0, body_decode.find(UDP_Protocol._group_sign, 0))
                    user_from = body_decode[head:tail]
                    (head, tail) = (tail + 1, body_decode.find(UDP_Protocol._group_sign, tail + 1))
                    user_to = body_decode[head:tail]
                    message = body_decode[tail + 1:]
                    print(f'{user_from} speak to all: {message}', flush=True)
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
                elif message[0] == UDP_Protocol._private_sign:
                    body_send   = (self._username + message).encode('utf-8')
                    header_send = struct.pack(UDP_Protocol._header_type, len(body_send), UDP_Protocol._private_message)
                    self._client.sendto(header_send + body_send, self._address)
                elif message[0] == UDP_Protocol._group_sign:
                    body_send   = (self._username + message).encode('utf-8')
                    header_send = struct.pack(UDP_Protocol._header_type, len(body_send), UDP_Protocol._group_message)
                    self._client.sendto(header_send + body_send, self._address)
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            self._client.close()


    def __init__(self, ip, port):
        self._address = (ip, port)
        self._client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self._username = ""

        while True:
            self._username = input('login: ')
            body_send   = self._username.encode('utf-8')
            header_send = struct.pack(UDP_Protocol._header_type, len(body_send), UDP_Protocol._login)
            self._client.sendto(header_send + body_send, self._address)
            (data, address) = self._client.recvfrom(UDP_Protocol._udp_buffer_size)
            header_unpack = struct.unpack(UDP_Protocol._header_type, data[:UDP_Protocol._header_size])
            if header_unpack[1] == UDP_Protocol._login_successfully:
                print(f'login successfully.', flush=True)
                break
            elif header_unpack[1] == UDP_Protocol._login_failed:
                print(f'login failed.', flush=True)
                continue

        threading.Thread(target=self._Receive).start()
        threading.Thread(target=self._Send).start()

if __name__ == '__main__':
    Client(UDP_Protocol._server_address, UDP_Protocol._server_port)
