/// Record: Cpp_atomic_compare_exchange_weak.cpp
/// Author: bss9395
/// Update: 2026/01/18⊥17:37:00&+08$08@China-BeiJing
/// Keepin: bss9395@yeah.net
/// Credit: https://legacy.cplusplus.com/reference/atomic/atomic/compare_exchange_weak/

#include <iostream>      
#include <atomic>         
#include <thread>        
#include <vector>     
#include <string>

class List {
public:
    struct Node {
        int _value = 0;
        Node* _next = nullptr;
    };
    std::atomic<Node*> _root = nullptr;

    virtual ~List() {
        for (Node* head = _root; head != nullptr; ) {
            Node* node = head;
            head = head->_next;
            delete node;
        }
    }

    void _Attach(int value) {
        Node* node = new Node({ value, _root });
        // 若_root == node->_next，则更新_root为node，并返回true
        // 若_root != node->_next，则更新node->_next为_root，并返回false
        while (false == _root.compare_exchange_weak(node->_next, node)) {
            ;
        }
    }

    void _Print() {
        std::string repr = "";
        for (Node* iter = _root; iter != nullptr; iter = iter->_next) {
            if (iter != _root) {
                repr += ", ";
            }
            repr += std::to_string(iter->_value);
        }
        std::cout << repr << std::endl;
    }
};

int main(int argc, char *argv[]) {
    List *list = new List();
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(&List::_Attach, list, i));
    }
    for (auto& th : threads) {
        th.join();
    }
    list->_Print();
    delete list;

    return 0;
}
