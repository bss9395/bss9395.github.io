''' Py_mysql.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: mysql
'''

import mysql.connector

print(mysql.connector.apilevel)
print(mysql.connector.threadsafety)
print(mysql.connector.paramstyle)

################################################################################

_db_file = "info.db"
_ddl_drop_order = '''
    drop table _Order;
    '''
_ddl_drop_user = '''
    drop table _User;
    '''
_ddl_user = '''
    create table _User (
        _id     integer primary key auto_increment,
        _name   text,
        _gender text
    );'''
_ddl_order = '''
    create table _Order (
        _id     integer primary key auto_increment,
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
    (null, "maker", "Female"),
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


connect = mysql.connector.connect(user="bss9395", password="Pass", host="localhost", port="3306", database="info", use_unicode=True)
connect.autocommit = True
cursor = connect.cursor()
try:
    cursor.execute(_ddl_drop_order)
except:
    pass
try:
    cursor.execute(_ddl_drop_user)
except:
    pass
cursor.execute(_ddl_user)
cursor.execute(_ddl_order)
cursor.execute(_dml_insert)
cursor.execute(_dml_update)
cursor.execute(_dml_select)
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

#connect.commit()
cursor.close()
connect.close()
