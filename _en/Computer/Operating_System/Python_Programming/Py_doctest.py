''' Py_doctest.py
Author: BSS9395
Update: 2022-10-23T17:30:00+08@China-Shanghai+08
Design: Python Standard Library: doctest
'''


def _Square(x):
    '''
    A function for calculating square of x.

    >>> _Square(2)
    4
    >>> _Square(-3)
    9
    >>> _Square(0)
    0
    '''
    return x ** 2


class User():
    '''
    name - represents name of user
    age  - represents age of user

    >>> user = User("python", 1)
    >>> user._name
    'python'
    >>> user._age
    1
    >>> user._Hello("I love python!")
    'I love python!'
    '''
    def __init__(self, name, age):
        self._name = name
        self._age = age
    def _Hello(self, greeting):
        return greeting

if __name__ == "__main__":
    import doctest
    doctest.testmod()
