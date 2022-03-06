/* Trie_Tree.cpp
Author: BSS9395
Update: 2022-03-06T18:30:00+08@China-Guangdong-Zhanjiang+08
Design: Trie tree
Encode: UTF-8
*/

#include <iostream>
#include <string>
#include <functional>
typedef intptr_t iptr;

struct Trie {
    struct Node {
    public:
        Node* _next[26];
        iptr _branch = 0;

    public:
        explicit Node() {
            fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);

            for (iptr i = 0; i < 26; i += 1) {
                _next[i] = nullptr;
            }
        }

        virtual ~Node() {
            fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        }
    };

public:
    Node* _head = new Node();

public:
    explicit Trie() {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
    }

    virtual ~Trie() {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);

        typedef std::function<void(Node*)> Function;
        Function Delete = [&Delete](Node* node) -> void {
            if (node == nullptr) {
                return;
            }
            if (1 <= node->_branch) {
                for (iptr i = 0; i < 26; i += 1) {
                    if (node->_next[i] != nullptr) {
                        Delete(node->_next[i]);
                    }
                }
            }
            delete node;
        };
        Delete(_head);
    }

public:
    void Print() {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);

        typedef std::function<void(Node*, iptr)> Function;
        Function Traverse = [&Traverse](Node* node, iptr level)  -> void {
            fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, "Function Traverse = [&Traverse](Node* node)  -> void {");

            if (node == nullptr) {
                return;
            }
            for (iptr i = 0; i < 26; i += 1) {
                if (node->_next[i] != nullptr) {
                    fprintf(stderr, "[%td] %c", level, (char)(i + 'a'));
                    fflush(stderr);
                    Traverse(node->_next[i], level + 1);
                }
            }
        };
        Traverse(_head, 0);
    }

    void Insert(const std::string& word) {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);

        Node* node = _head;
        const char* chara = word.data();
        for (iptr i = 0, leng = word.length(); i < leng; i += 1) {
            if (node->_next[chara[i] - 'a'] == nullptr) {
                node->_next[chara[i] - 'a'] = new Node();
                node->_branch += 1;
            }
            node = node->_next[chara[i] - 'a'];
        }
    }

    // note: use second level pointer for searching node, it's convenient for modifying data.
    Node** Search(const std::string& word) {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);

        Node** node = &_head;
        const char* chara = word.data();
        for (iptr i = 0, leng = word.length(); i < leng; i += 1) {
            node = &((*node)->_next[chara[i] - 'a']);
            if ((*node) == nullptr) {
                return node;
            }
        }
        return node;
    }

    bool Prifix(const std::string& prefix) {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);

        Node** node = Search(prefix);
        return ((*node) != nullptr);
    }

    bool Match(const std::string& word) {
        fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);

        Node** node = Search(word);
        return ((*node) != nullptr && (*node)->_branch <= 0);
    }
};


void Test() {
    Trie trie = Trie();
    trie.Insert("word");
    trie.Print();
    bool prifix = trie.Prifix("word");
    std::cout << std::boolalpha << prifix << std::endl;
    bool search = trie.Match("wo");
    std::cout << std::boolalpha << search << std::endl;
}

int main(int argc, char* argv[]) {
    Test();

    return 0;
}
