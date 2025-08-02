import java.io.Console;

abstract class IList<Type_> {
    abstract public int _Size();
    abstract public boolean _Empty();
    abstract public boolean _Contains(Type_ data);
    abstract public void _Set(int index, Type_ data);
    abstract public Type_ _Get(int index);
    abstract public void _Erase(int index);
    abstract public void _Remove(Type_ data);
    abstract public void _Clean();
}

class LinkedList<Type_> extends IList<Type_> {
    static class Node<Type_> {
        public Type_ _data;
        public Node _next;
        public Node() {

        }
        public Node (Type_ data) {
            _data = data;
        }
        public String toString() {
            if(_data == null) {
                return "";
            }
            return _data.toString();
        }
    }
    private Node<Type_> _root = new Node<Type_>();
    private int _size = 0;

    public void _Print() {
        StringBuilder buffer = new StringBuilder();
        int idx = 0;
        Node<Type_> head = _root._next;
        while(head != null) {
            idx += 1;
            if(1 < idx) {
                buffer.append(",");
            }
            buffer.append(head);
            head = head._next;
        }
        System.out.println(buffer.toString());
    }
    public int _Size() {
        return _size;
    }
    public boolean _Empty() {
        return (_size == 0);
    }
    public void _Append(Type_ data) {
        Node<Type_> head = _root;
        while(head._next != null) {
            head = head._next;
        }
        Node<Type_> node = new Node(data);
        node._next = head._next;
        head._next = node;
        _size += 1;
    }
    public void _Set(int index, Type_ data) {
        if((0 <= index && index < _size) == false) {
            return ;
        }
        int idx = 0;
        Node<Type_> head = _root._next;
        while(idx < index && head != null) {
            idx += 1;
            head = head._next;
        }
        head._data = data;
    }
    public Type_ _Get(int index) {
        if((0 <= index && index < _size) == false) {
            return null;
        }
        int idx = 0;
        Node<Type_> head = _root._next;
        while(idx < index && head != null) {
            idx += 1;
            head = head._next;
        }
        return head._data;
    }
    public boolean _Contains(Type_ data) {
        Node<Type_> head = _root._next;
        while(head != null) {
            if(head._data == data || (head._data != null && head._data.equals(data) == true)) {
                return true;
            }
            head = head._next;
        }
        return false;
    }
    public void _Erase(int index) {
        if((0 <= index && index < _size) == false) {
            return;
        }
        int idx = 0;
        Node<Type_> head = _root;
        while(idx < index && head._next != null) {
            idx += 1;
            head = head._next;
        }
        head._next = head._next._next;
        _size -= 1;
    }
    public void _Remove(Type_ data) {
        Node<Type_> head = _root;
        while(head._next != null && (head._next._data == data || (head._next._data != null && head._next._data.equals(data))) == false) {
            head = head._next;
        }
        if(head._next != null) {
            head._next = head._next._next;
        }
        _size -= 1;
    }
    public void _Clean() {
        _root._next = null;
        _size = 0;
    }
}

public class Java_LinkedList {
    public static void main(String[] args) {
        LinkedList<String> linkedList = new LinkedList<String>();
        linkedList._Append("123");
        linkedList._Append("345");
        // linkedList._Set(0, null);
        String str = linkedList._Get(0);
        linkedList._Print();
        boolean test = linkedList._Contains(null);
        System.out.println(test);
        // linkedList._Erase(1);
        linkedList._Remove("345");
        linkedList._Print();
        linkedList._Clean();
        linkedList._Print();
    }
}