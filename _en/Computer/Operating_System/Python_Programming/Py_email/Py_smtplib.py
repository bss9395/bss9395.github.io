''' Py_smtplib.py
Author: BSS9395
Update: 2022-11-30T16:23:00+08@China-Shanghai+08
Design: Python Standard Library: smtplib
'''

import email.utils
import smtplib
from email.message import EmailMessage

_smtp_server = 'smtp.yeah.net'
_from_email  = 'bss9395@yeah.net'
_password    = '****************'   # use a token generated by @yeah.net
_to_email    = '453432096@qq.com'

_connection  = smtplib.SMTP_SSL(_smtp_server, 465)
_connection.set_debuglevel(1)
_connection.login(_from_email, _password)
_message     = EmailMessage()
_message['subject'] = 'a testing email'
_message['from']    = f'bss9395_yeah <{_from_email}>'
_message['to']      = f'bss9395_qq <{_to_email}>'

(_id1, _id2) = (email.utils.make_msgid(), email.utils.make_msgid())
_content = f'''
<h2>email content</h2>
<p>this is an email written in python.</p>
<img src="cid:{_id1[1:-1]}">
<img src="cid:{_id2[1:-1]}">
from<a href="http://bss9395.github.io">bss9395.github.io</a>'
'''
_message.set_content(_content, 'html', 'utf-8')
with open('butterfly.png', 'rb') as file:
    _message.add_attachment(file.read(), maintype='image', subtype='png', filename='butterfly.png', cid=_id1)
with open('butterfly.jpg', 'rb') as file:
    _message.add_attachment(file.read(), maintype='image', subtype='jpg', filename='butterfly.jpg', cid=_id2)
with open('butterfly.pdf', 'rb') as file:
    _message.add_attachment(file.read(), maintype='application', subtype='pdf', filename='butterfly.pdf')

_connection.sendmail(_from_email, [_to_email], _message.as_string())
_connection.quit()
