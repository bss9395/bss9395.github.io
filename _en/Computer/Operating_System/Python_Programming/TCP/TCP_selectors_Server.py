''' TCP_selectors_Server.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: TCP selectors Server
'''

import socket
import selectors

class TCP_Server(object):
    _server_address = "192.168.1.12"
    _server_port = 1234

    def __init__(self, address, port):
        self._selector = selectors.DefaultSelector()
        self._server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._server.bind((address, port))
        self._server.listen()
        self._selector.register(self._server, selectors.EVENT_READ, self._Accept)
        self._clients = []

        while True:
            events = self._selector.select()
            for event, mask in events:
                event.data(event.fileobj, mask)


    def _Accept(self, server, mask):
        (client, address) = server.accept()
        client.setblocking(False)
        self._clients.append(client)
        self._selector.register(client, selectors.EVENT_READ, self._Receive)

    def _Receive(self, client, mask):
        try:
            data = client.recv(1024)
            if not data:
                raise Exception('not data')
            for client_socket in self._clients:
                client_socket.send(data)
        except Exception as exception:
            print(str(exception), flush=True)
            self._selector.unregister(client)
            client.close()
            self._clients.remove(client)

if __name__ == "__main__":
    TCP_Server('0.0.0.0', TCP_Server._server_port)
