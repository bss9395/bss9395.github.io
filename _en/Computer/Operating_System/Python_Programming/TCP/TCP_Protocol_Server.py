''' TCP_Protocol_Server.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: TCP Protocol Server
'''

import threading
import socket
import struct


class TCP_Protocol(object):
    _server_address = "192.168.1.12"
    _server_port = 12345

    _tcp_buffer_size = 2048
    _header_size = 8
    _header_type = "!2I"

    _login = 0x01
    _login_successfully = 0x02
    _login_failed = 0x03
    _private_message = 0x04
    _group_message = 0x05

    _private_sign = '@'
    _group_sign = '#'

    def __init__(self):
        self._buffer = bytes()

    def _Recv(self, client, handle) -> None:
        while True:
            while len(self._buffer) < TCP_Protocol._header_size:
                if 0 < len(self._buffer):
                    print(f'buffer {len(self._buffer)} bytes less than header size', flush=True)
                data = client.recv(TCP_Protocol._tcp_buffer_size)
                if not data:
                    return None
                self._buffer += data
            header_unpack = struct.unpack(TCP_Protocol._header_type, self._buffer[:TCP_Protocol._header_size])
            while len(self._buffer) < TCP_Protocol._header_size + header_unpack[0]:
                print(f'buffer {len(self._buffer)} bytes less than total size', flush=True)
                data = client.recv(TCP_Protocol._tcp_buffer_size)
                if not data:
                    return None
                self._buffer += data
            body = self._buffer[TCP_Protocol._header_size:TCP_Protocol._header_size + header_unpack[0]]
            self._buffer = self._buffer[TCP_Protocol._header_size + header_unpack[0]:]
            result = handle(header_unpack, body)
            if not result:
                return None


class Server(object):
    def _Client(self, clients, client):
        def _Handle(header_unpack, body) -> bool:
            print(f'body_size={header_unpack[0]}, topic={header_unpack[1]}', flush=True)
            print(f'{body.decode("utf-8")}', end='\n', flush=True)

            if header_unpack[1] == TCP_Protocol._login:
                user = body.decode('utf-8')
                if user in clients.keys():
                    body_send   = 'username already in use.'.encode('utf-8')
                    header_send = struct.pack(TCP_Protocol._header_type, len(body_send), TCP_Protocol._login_failed)
                    client.send(header_send + body_send)
                else:
                    clients[user] = client
                    body_send   = 'login successfully.'.encode('utf-8')
                    header_send = struct.pack(TCP_Protocol._header_type, len(body_send), TCP_Protocol._login_successfully)
                    client.send(header_send + body_send)
            elif header_unpack[1] == TCP_Protocol._private_message:
                body_decode  = body.decode('utf-8')
                (head, tail) = (0, body_decode.find(TCP_Protocol._private_sign, 0))
                user_from      = body_decode[head:tail]
                (head, tail) = (tail + 1, body_decode.find(TCP_Protocol._private_sign, tail + 1))
                user_to = body_decode[head:tail]
                body_send    = body
                header_send  = struct.pack(TCP_Protocol._header_type, *header_unpack)
                if user_to in clients.keys():
                    clients[user_to].send(header_send + body_send)
            elif header_unpack[1] == TCP_Protocol._group_message:
                body_send   = body
                header_send = struct.pack(TCP_Protocol._header_type, *header_unpack)
                for client_socket in clients.values():
                    client_socket.send(header_send + body_send)
            else:
                body_send = body
                header_send = struct.pack(TCP_Protocol._header_type, *header_unpack)
                client.send(header_send + body_send)
            return True

        try:
            tcp_protocol = TCP_Protocol()
            tcp_protocol._Recv(client, _Handle)
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            client.close()
            for key in list(clients.keys()):
                if clients[key] == client:
                    clients.pop(key)

    def __init__(self, address, port) -> None:
        try:
            self._server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self._server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self._server.bind((address, port))
            self._server.listen()
            self._clients = {}
            while True:
                (client, address) = self._server.accept()
                threading.Thread(target=self._Client, args=(self._clients, client)).start()
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            for (user, client) in self._clients.items():
                client.close()
            self._server.close()


if __name__ == "__main__":
    Server('0.0.0.0', TCP_Protocol._server_port)
