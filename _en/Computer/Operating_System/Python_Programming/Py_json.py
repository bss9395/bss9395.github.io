''' Py_json.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: json
'''

import codecs
import json

class JSON(object):
    @staticmethod
    def _Dumps_Load():
        info = ["bass9395", {
            "favorite": ["frisbee", None, "coding", "你好"],
        }]
        string = json.dumps(info)
        print(string)
        print(string, file=codecs.open("Py_JSON/info.json", "w", "utf-8"))
        info = json.load(codecs.open("Py_JSON/info.json", "r", "utf-8"))
        print(info)

    @staticmethod
    def _Loads():
        def _As_Complex(dictionary):
            if dictionary["complex"] == True:
                return complex(dictionary["real"], dictionary["imag"])
            return dictionary

        comp = json.loads('{"complex": true, "real": 1.0, "imag": 2.0 }', object_hook=_As_Complex)
        print(comp)

    @staticmethod
    def _JSONEncoder():
        class Complex_Encoder(json.JSONEncoder):
            def default(self, obj):
                if isinstance(obj, complex):
                    return {"complex": True, "real": obj.real, "imag": obj.imag}
                return json.JSONEncoder.default(self, obj)

        string = json.dumps(1 + 2j, cls=Complex_Encoder)
        print(string)

if __name__ == '__main__':
    # JSON._Dumps_Load()
    # JSON._Loads()
    JSON._JSONEncoder()
