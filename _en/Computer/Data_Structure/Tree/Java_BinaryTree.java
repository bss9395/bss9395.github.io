/* Java_BinaryTree.java
Author: bss9395
Update: 2025/09/23T19:43:00+08@China-GuangDong-ZhanJiang+08
*/

class Person implements Comparable<Person> {
    public String _name;
    public int _age;

    public Person(String name, int age) {
        _name = name;
        _age = age;
    }

    @Override
    public String toString() {
        return "[Person] " + _name + ", " + _age;
    }

    @Override
    public int compareTo(Person datum) {
        return (_age - datum._age);
    }
}

class BinaryTree<Datum extends Comparable<Datum>> {
    static public class Node<Datum extends Comparable<Datum>> {
        Node<Datum> _parent;
        Node<Datum> _left;
        Node<Datum> _right;
        Datum _datum;

        public Node() {

        }
        public Node(Datum datum) {
            _datum = datum;
        }
    }

    private Node<Datum> _root = new Node<>();
    private int _size = 0;

    public int _Size() {
        return _size;
    }

    public void _Insert(Datum datum) {
        Node<Datum> node = new Node<>(datum);
        if(_root._right == null) {
            _root._right = node;
            node._parent = _root;
            _size += 1;
        } else {
            _InsertNode(_root._right, node);
        }
    }
    public void _InsertNode(Node<Datum> parent, Node<Datum> node) {
        if(node._datum.compareTo(parent._datum) < 0) {
            if(parent._left == null) {
                parent._left = node;
                node._parent = parent;
                _size += 1;
            } else {
                _InsertNode(parent._left, node);
            }
        } else if(parent._datum.compareTo(node._datum) < 0) {
            if(parent._right == null) {
                parent._right = node;
                node._parent = parent;
                _size += 1;
            } else {
                _InsertNode(parent._right, node);
            }
        }
    }

    public void _Erase(Datum datum) {
        Node<Datum> node = new Node(datum);
        _Erase_Node(_root._right, node);
    }
    public void _Erase_Node(Node<Datum> tree, Node<Datum> node) {
        if(tree==null) {
            return;
        }
        if(node._datum.compareTo(tree._datum) < 0) {
            _Erase_Node(tree._left, node);
        } else if(tree._datum.compareTo(node._datum) < 0) {
            _Erase_Node(tree._right, node);
        } else {
            if(tree._left != null && tree._right != null) {
                Node<Datum> parent = null;
                Node<Datum> leftmost = tree._right;
                while (leftmost._left != null) {
                    parent = leftmost;
                    leftmost = leftmost._left;
                }
                tree._datum = leftmost._datum;
                parent._left = leftmost._right;
                _size -= 1;
            }
        }
    }

    public void _Travel() {
        _TravelNode(_root._right);
    }
    public void _TravelNode(Node<Datum> node) {
        if(node != null) {
            _TravelNode(node._left);
            System.out.println(node._parent._datum + "|" + node._datum);
            _TravelNode(node._right);
        }
    }

    public Node<Datum> _Search(Datum datum) {
        Node<Datum> node = new Node<>(datum);
        Node<Datum> tree = _root._right;
        while(tree != null) {
            if(node._datum.compareTo(tree._datum) < 0) {
                tree = tree._left;
            } else if(tree._datum.compareTo(node._datum) < 0) {
                tree = tree._right;
            } else {
                return tree;
            }
        }
        return null;
    }
}

public class Java_BinaryTree {
    static public void main(String[] args) {
        BinaryTree<Person> binaryTree = new BinaryTree<>();
        _Test_Insert(binaryTree);
        _Test_Erase(binaryTree);
        _Test_Travel(binaryTree);
        // _Test_Search(binaryTree);
        // _Test_Size(binaryTree);
    }
    static public void _Test_Size(BinaryTree<Person> binaryTree) {
        System.out.println(binaryTree._Size());
    }

    static public void _Test_Insert(BinaryTree<Person> binaryTree) {
/*
		 40
		/ \
	  20   60
	 / |   | \
   10  30  50 70
       |      /
	   35    65
*/
        binaryTree._Insert(new Person("brilliant-40", 40));
        binaryTree._Insert(new Person("brilliant-20", 20));
        binaryTree._Insert(new Person("brilliant-10", 10));
        binaryTree._Insert(new Person("brilliant-30", 30));
        binaryTree._Insert(new Person("brilliant-35", 35));
        binaryTree._Insert(new Person("brilliant-60", 60));
        binaryTree._Insert(new Person("brilliant-50", 50));
        binaryTree._Insert(new Person("brilliant-70", 70));
        binaryTree._Insert(new Person("brilliant-65", 65));
    }

    static public void _Test_Erase(BinaryTree<Person> binaryTree) {
        binaryTree._Erase(new Person("brilliant-40", 40));
    }

    static public void _Test_Travel(BinaryTree<Person> binaryTree) {
        binaryTree._Travel();
    }

    static public void _Test_Search(BinaryTree<Person> binaryTree) {
        BinaryTree.Node<Person> node = binaryTree._Search(new Person("brilliant-50", 50));
        System.out.println(node._datum);
    }
}
