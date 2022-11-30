''' TCP_Server.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: TCP Server
'''

import threading
import socket
import struct

class Protocol(object):
    _server_address = "192.168.1.12"
    _server_port = 12345
    _tcp_buffer_size = 2048
    _header_size = 8
    _header_type = "!2I"


class Server(object):
    class Client(threading.Thread):
        def __init__(self, clients, client):
            super().__init__()
            self._clients = clients
            self._client = client
            self._clients.append(client)
            self._count = 0

        def run(self):
            try:
                buffer = bytes()
                while True:
                    while len(buffer) < Protocol._header_size:
                        print(f'buffer {len(buffer)} bytes less than header size', flush=True)
                        data = self._client.recv(Protocol._tcp_buffer_size)
                        if not data:
                            return
                        buffer += data
                    header = struct.unpack(Protocol._header_type, buffer[:Protocol._header_size])
                    while len(buffer) < Protocol._header_size + header[0]:
                        print(f'buffer {len(buffer)} bytes less than total size', flush=True)
                        data = self._client.recv(Protocol._tcp_buffer_size)
                        if not data:
                            return
                        buffer += data
                    body = buffer[Protocol._header_size:Protocol._header_size + header[0]]
                    self._Handle_Data(header, body)
                    buffer = buffer[Protocol._header_size + header[0]:]
            except Exception as exception:
                print(str(exception), flush=True)
            finally:
                self._client.close()
                self._clients.remove(self._client)

        def _Handle_Data(self, header, body):
            self._count += 1
            print(f'package {self._count}', flush=True)
            print(f'body_size={header[0]}, topic={header[1]}', flush=True)
            print(f'{body.decode("utf-8")}', end='\n', flush=True)
            self._client.send(struct.pack(Protocol._header_type, *header) + body)

    def __init__(self, address, port):
        self._server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._server.bind((address, port))
        self._server.listen()
        self._clients = []
        while True:
            (client, address) = self._server.accept()
            print((client, address), end='\n', flush=True)
            self.Client(self._clients, client).start()

if __name__ == "__main__":
    Server('0.0.0.0', Protocol._server_port)
