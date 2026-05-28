#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool is_end;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }

        is_end = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->is_end = true;
    }

    bool search(string s) {
        TrieNode* node = root;
        
        for (char ch : s) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            }
            
            node = node->child[idx];
        }

        return node->is_end;
    }

    bool starts_with(string prefix) {
        TrieNode* node = root;
        
        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            }

            node = node->child[idx];
        }

        return true;
    }
};

int main() {
    Trie t;
    t.insert("dad");
    t.insert("do");
    t.insert("cat");
    t.insert("car");

    if (t.search("car")) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}