''' Py_poplib.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: poplib
'''

import poplib
import os.path
import mimetypes
from email.parser import BytesParser
from email.parser import Parser
from email.policy import default

_pop_server = 'pop.yeah.net'
_user       = 'bss9395@yeah.net'
_password   = '****************'   # use a token generated by @yeah.net
_connetion  = poplib.POP3_SSL(_pop_server, 995)
_connetion.set_debuglevel(1)

print(_connetion.getwelcome().decode('utf-8'))
_connetion.user(_user)
_connetion.pass_(_password)
(_response, _email_count, _octets) = _connetion.list()
print(f'response={_response}, mails={_email_count}, octets={_octets}')
(_response, _email_content, _octets) = _connetion.retr(len(_email_count))
print(f'response={_response}, mail={_email_content}, octets={_octets}')

_message = BytesParser(policy=default).parsebytes(b'\r\n'.join(_email_content))
print(f'subject: {_message["subject"]}')
print(f'send from: {_message["from"]}')
print(f'send to: {_message["to"]}')

_counter = 1
for part in _message.walk():
    if part.get_content_maintype() == 'multipart':
        continue
    elif part.get_content_maintype() == 'text':
        print(part.get_content())
    else:
        filename = part.get_filename()
        print(filename)
        if not filename:
            extension = mimetypes.guess_extension(part.get_content_type())
            if not extension:
                extension = '.bin'
            filename = f'part-{_counter:0{3}}{extension}'
        _counter += 1
        with open(os.path.join('', filename), 'wb') as file:
            file.write(part.get_payload(decode=True))
_connetion.quit()