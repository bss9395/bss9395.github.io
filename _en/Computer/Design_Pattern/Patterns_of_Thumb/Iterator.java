/* Iterator.java
Author: BSS9395
Update: 2023-05-27T15:17:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Iterator
*/

abstract class AList {
    abstract static public class AIterator {
        abstract public void    _First();
        abstract public void    _Last();
        abstract public boolean _Has_Next();
        abstract public Object  _Next();
    }

    ////////////////////////////////////////////////////////////////////////////

    abstract public int       _Get_Size();
    abstract public void      _Add(Object obj);
    abstract public Object    _Get(int index);
    abstract public AIterator _Iterator();
}

class List_Array extends AList {
    static public class Iterator extends AList.AIterator {
        public AList _list  = null;
        public int  _index = 0;
        public Iterator(AList list) {
            _list = list;
            _index = 0;
        }

        public void _First() {
            _index = 0;
        }

        public void _Last() {
            _index = _list._Get_Size();
        }

        public boolean _Has_Next() {
            return (_index < _list._Get_Size());
        }

        public Object _Next() {
            Object object = _list._Get(_index);
            _index += 1;
            return object;
        }
    }

    ////////////////////////////////////////////////////////////////////////////

    public Object[] _list  = null;
    public int      _index = 0;
    public int      _size  = 0;
    public List_Array() {
        _list  = new Object[100];
        _index = 0;
        _size  = 0;
    }

    @Override
    public int _Get_Size() {
        return _size;
    }

    @Override
    public void _Add(Object object) {
        _list[_index] = object;
        _index += 1;
        _size  += 1;
    }

    public Object _Get(int index) {
        return _list[index];
    }

    public AIterator _Iterator() {
        return new Iterator(this);
    }
}

public class Iterator {
    public static void main(String[] args) {
        AList list = new List_Array();
        list._Add("abc");
        list._Add("def");
        list._Add("ghi");

        List_Array.AIterator iter = list._Iterator();
        while (iter._Has_Next()) {
            System.out.println(iter._Next());
        }
        System.out.println("=====");
        for (int i = 0; i < list._Get_Size(); i += 1) {
            System.out.println(list._Get(i));
        }
    }
}