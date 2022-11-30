''' UDP_Server.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: UDP Server
'''

import socket
import threading
import struct

class UDP_Protocol(object):
    _server_address = "192.168.1.12"
    _server_port = 12345

    _udp_buffer_size = 65536
    _header_size = 8
    _header_type = '!2I'

    _login = 0x01
    _login_successfully = 0x02
    _login_failed = 0x03
    _private_message = 0x04
    _group_message = 0x05

    _private_sign = '@'
    _group_sign = '#'

class UDP_Server(object):
    def _Client(self, data, address):
        try:
            header_unpack = struct.unpack(UDP_Protocol._header_type, data[:UDP_Protocol._header_size])
            body = data[UDP_Protocol._header_size:]
            print(f'{address}', flush=True)
            print(f'body_size={header_unpack[0]}, topic={header_unpack[1]}', flush=True)
            print(f'{body.decode("utf-8")}', end='\n\n', flush=True)

            if header_unpack[1] == UDP_Protocol._login:
                user = body.decode('utf-8')
                if user in self._clients.keys():
                    body_send   = 'usernames already in use.'.encode('utf-8')
                    header_send = struct.pack(UDP_Protocol._header_type, len(body_send), UDP_Protocol._login_failed)
                    self._server.sendto(header_send + body_send, address)
                else:
                    self._clients[user] = address
                    body_send   = 'login successfully.'.encode('utf-8')
                    header_send = struct.pack(UDP_Protocol._header_type, len(body_send), UDP_Protocol._login_successfully)
                    self._server.sendto(header_send + body_send, address)
            elif header_unpack[1] == UDP_Protocol._private_message:
                body_decode = body.decode('utf-8')
                (head, tail) = (0, body_decode.find(UDP_Protocol._private_sign, 0))
                user_from    = body_decode[head:tail]
                (head, tail) = (tail + 1, body_decode.find(UDP_Protocol._private_sign, tail + 1))
                user_to      = body_decode[head:tail]
                body_send    = body
                header_send  = struct.pack(UDP_Protocol._header_type, *header_unpack)
                if user_to in self._clients.keys():
                    self._server.sendto(header_send + body_send, self._clients[user_to])
            elif header_unpack[1] == UDP_Protocol._group_message:
                body_send   = body
                header_send = struct.pack(UDP_Protocol._header_type, *header_unpack)
                for client in self._clients.values():
                    self._server.sendto(header_send + body_send, client)
            else:
                self._server.sendto(data, address)
        except Exception as exception:
            print(str(exception), flush=True)


    def __init__(self, address, port):
        try:
            self._server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self._server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            self._server.bind((address, port))
            self._clients = {}

            while True:
                (data, address) = self._server.recvfrom(UDP_Protocol._udp_buffer_size)
                threading.Thread(target=self._Client, args=(data, address)).start()
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            for (user, client) in self._clients.items():
                client.close()
            self._server.close()


if __name__ == '__main__':
    UDP_Server('0.0.0.0', UDP_Protocol._server_port)
