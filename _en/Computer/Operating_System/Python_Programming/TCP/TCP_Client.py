''' TCP_Client.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: TCP Client
'''

from TCP_Server import Protocol
import time
import threading
import socket
import struct
import json

class Client(object):
    class Receive(threading.Thread):
        def __init__(self, client):
            super().__init__()
            self._client = client

        def run(self):
            try:
                while True:
                    print(self._client.getpeername(), flush=True)
                    print(self._client.recv(2048).decode("utf-8"), flush=True)
            except Exception as exception:
                print(str(exception), flush=True)

    class Send(threading.Thread):
        def __init__(self, client):
            super().__init__()
            self._client = client

        def run(self):
            try:
                # 正常包
                body1 = json.dumps(dict(hello="你好")).encode('utf-8')
                command1 = 101
                header1 = struct.pack(Protocol._header_type, len(body1), command1)
                data1 = header1 + body1
                print(body1)
                self._client.send(data1)
                time.sleep(1)

                # 拆包
                body2 = json.dumps(dict(hello="world2")).encode('utf-8')
                command2 = 102
                header2 = struct.pack(Protocol._header_type, len(body2), command2)
                data2_1 = header2 + body2[:3]
                data2_2 = body2[3:]
                print(body2)
                self._client.send(data2_1)
                time.sleep(1)
                self._client.send(data2_2)
                time.sleep(1)

                # 粘包
                body3 = json.dumps(dict(hello="world3")).encode('utf-8')
                command3 = 103
                header3 = struct.pack(Protocol._header_type, len(body3), command3)
                data3 = header3 + body3
                body4 = json.dumps(dict(hello="world4")).encode('utf-8')
                command4 = 104
                header4 = struct.pack(Protocol._header_type, len(body4), command4)
                data4 = header4 + body4
                data34 = data3 + data4
                print(data34)
                self._client.send(data34)
                time.sleep(1)

                self._client.close()
            except Exception as exception:
                print(str(exception), flush=True)

    def __init__(self, ip, port):
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client.connect((ip, port))
        self.Receive(client).start()
        self.Send(client).start()

if __name__ == '__main__':
    Client(Protocol._server_address, Protocol._server_port)
