''' Py_sqlite3.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: sqlite3
'''

import sqlite3
import os

print(sqlite3.apilevel)
print(sqlite3.threadsafety)
print(sqlite3.paramstyle)

################################################################################

def _Encode(text):
    return '[' + text[::-1] + ']'


class Min_Length():
    def __init__(self):
        self._min_length = None

    def step(self, value):
        if self._min_length == None:
            self._min_length = value
        elif len(value) < len(self._min_length):
            self._min_length = value

    def finalize(self):
        return self._min_length

def _Collate(str1, str2):
    if str1 < str2:
        return -1
    elif str1 > str2:
        return +1
    else:
        return 0


_db_file = "info.db"
_ddl_user = '''
    create table _User (
        _id     integer primary key autoincrement,
        _name   text,
        _gender text
    );'''
_ddl_order = '''
    create table _Order (
        _id     integer primary key autoincrement,
        _name   text,
        _price  real,
        _number real,
        _user   integer,
        foreign key(_user) references _User(_id) 
    );'''
_dml_insert = '''
    insert into _User 
    values
    (null, "bss9395", "Male"),
    (null, _Encode("maker"), "Female"),
    (null, "emperor", "Male");
    '''
_dml_update = '''
    update _User 
    set _gender = "%s"
    where _id   = %s;
    ''' % ("Female", "3")
_dml_select = '''
    select * from _User
    where _id >= %s;
    ''' % (2,)
_dml_select_aggregate = '''
    select Min_Length(_name) 
    from _User;
    '''
_dml_select_collate = '''
    select * 
    from _User 
    order by _name
    collate _Collate;
    '''

try:
    os.remove(_db_file)
except:
    pass
connect = sqlite3.connect(_db_file)
connect.create_function("_Encode", 1, _Encode)
connect.create_aggregate("Min_Length", 1, Min_Length)
connect.create_collation("_Collate", _Collate)
cursor = connect.cursor()
cursor.execute(_ddl_user)
cursor.execute(_ddl_order)
cursor.execute(_dml_insert)
cursor.execute(_dml_update)
cursor.execute(_dml_select)
connect.commit()

print("affected rows: %s" % cursor.rowcount)
for col in cursor.description:
    print(col[0], end="\t\t")
print()
print("-" * 40)
while True:
    row = cursor.fetchone()
    if row == None:
        break
    for col in row:
        print(col, end="\t\t")
    print()

cursor.execute(_dml_select_aggregate)
connect.commit()
print(cursor.fetchone())

cursor.execute(_dml_select_collate)
connect.commit()
for row in cursor:
    print(row)

cursor.close()
connect.close()
