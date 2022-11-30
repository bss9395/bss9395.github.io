''' TCP_selectors_Client.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: TCP selectors Client
'''

from TCP_selectors_Server import TCP_Server
import threading
import socket
import selectors

class Client(object):
    def __init__(self, address, port):
        self._selector = selectors.DefaultSelector()
        self._client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._client.connect((address, port))
        self._client.setblocking(False)
        self._selector.register(self._client, selectors.EVENT_READ, self._Receive)

        threading.Thread(target=self._Send).start()
        while True:
            events = self._selector.select()
            for event, mask in events:
                event.data(event.fileobj, mask)

    def _Receive(self, client, mask):
        try:
            data = client.recv(1024)
            if not data:
                raise Exception('not data')
            print(data.decode('utf-8'), flush=True)
        except Exception as exception:
            print(str(exception), flush=True)
            self._selector.unregister(client)
            client.close()

    def _Send(self):
        while True:
            message = input('')
            if not message or message == 'exit':
                break
            self._client.send(message.encode('utf-8'))


if __name__ == '__main__':
    Client(TCP_Server._server_address, TCP_Server._server_port)
