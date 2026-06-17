#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root = nullptr;

    void insert(int val) {
        Node* new_node = new Node(val);

        if (root == nullptr) {
            root = new_node;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left == nullptr) {
                curr->left = new_node;
                return;
            } else {
                q.push(curr->left);
            }

            if (curr->right == nullptr) {
                curr->right = new_node;
                return;
            } else {
                q.push(curr->right);
            }
        }
    }

    void preorder(Node* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    Tree t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);

    /**
     *           10
     *         /    \
     *        20     30
     *       /  \   /  \
     *      40  50 60  70
     */

    t.preorder(t.root);
    cout << endl;

    t.inorder(t.root);
    cout << endl;

    t.postorder(t.root);
    cout << endl;

    return 0;
}