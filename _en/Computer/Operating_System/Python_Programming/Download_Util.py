''' Download_Util.py
Author: BSS9395
Update: 2022-11-05T21:46:00+08@China-Shanghai+08
Design: Download Util
'''

import threading
import urllib.request


class Download_Thread(threading.Thread):
    def __init__(self, path, file, start_position, part_size):
        super().__init__()
        self._path = path
        self._file = file
        self._start_position = start_position
        self._part_size = part_size
        self._length = 0

    def run(self):
        request = urllib.request.Request(url=self._path, method="GET")
        request.add_header("Accept", "*/*")
        request.add_header("Charset", "utf-8")
        request.add_header("Connection", "Keep-Alive")
        resource = urllib.request.urlopen(request)
        resource.read(self._start_position)
        self._file.seek(self._start_position, 0)
        while self._length < self._part_size:
            data = resource.read(1024)
            if data is None or len(data) <= 0:
                break
            self._file.write(data)
            self._length += len(data)
        resource.close()
        self._file.close()


class Download_Util(object):
    def __init__(self, path, file, thread_count):
        self._path = path
        self._file = file
        self._thread_count = thread_count
        self._threads = []
        self._file_size = 0

    def _Download(self):
        request = urllib.request.Request(url=self._path, method="GET")
        request.add_header("Accept", "*/*")
        request.add_header("Charset", "utf-8")
        request.add_header("Connection", "Keep-Alive")
        resource = urllib.request.urlopen(request)
        self._file_size = int(resource.headers.get("Content-Length", 0))
        resource.close()

        part_size = self._file_size // self._thread_count + 1
        for i in range(self._thread_count):
            file = open(self._file, "wb")    # create file one by one before running the thread.
            start_position = i * part_size
            thread = Download_Thread(self._path, file, start_position, part_size)
            self._threads.append(thread)
            thread.start()

    def _Get_Complete_Rate(self):
        size_sum = 0
        for i in range(self._thread_count):
            size_sum += self._threads[i]._length
        return float(size_sum / self._file_size)

    def _Show_Progress(self):
        rate = self._Get_Complete_Rate()
        print("%0.2f completed" % rate)
        if rate < 1.0:
            self._timer = threading.Timer(0.1, self._Show_Progress)
            self._timer.start()
        else:
            self._timer.cancel()


_util = Download_Util("https://pngimg.com/uploads/sprite/sprite_PNG98768.png", 'photo.png', 3)
_util._Download()
_util._Show_Progress()
