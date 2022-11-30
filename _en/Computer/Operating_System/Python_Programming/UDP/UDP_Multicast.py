''' UDP_Multicast.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: UDP Multicast
'''


import threading
import time
import socket

class UDP_Multicast(object):
    _group_ip = '230.0.0.1'
    _host_ip = '192.168.1.12'
    _port = 12345
    _udp_buffer_size = 65536

    def _Receive(self):
        try:
            while True:
                (data, address) = self._client.recvfrom(UDP_Multicast._udp_buffer_size)
                print(f'{address}', flush=True)
                print(f'{data.decode("utf-8")}', end='\n\n', flush=True)
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            self._client.close()

    def _Send(self):
        try:
            while True:
                message = input('')
                if message is None or message == 'exit':
                    break
                self._client.sendto(message.encode('utf-8'), (UDP_Multicast._group_ip, UDP_Multicast._port))
        except Exception as exception:
            print(str(exception), flush=True)
        finally:
            self._client.close()

    def __init__(self):
        self._client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self._client.bind(('0.0.0.0', UDP_Multicast._port))
        self._client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._client.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 255)
        self._client.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, socket.inet_aton(UDP_Multicast._group_ip) + socket.inet_aton(UDP_Multicast._host_ip))

        threading.Thread(target=self._Receive).start()
        threading.Thread(target=self._Send).start()

if __name__ == '__main__':
    UDP_Multicast()
