#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Using DFS
int max_depth(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) return 1 + max_depth(root->right);
    if (root->right == nullptr) return 1 + max_depth(root->left);
    return 1 + max(max_depth(root->left), max_depth(root->right));
}

int main() {
    Node* root = new Node(11);
    root->left = new Node(7);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->right->left = new Node(13);
    root->right->right = new Node(19);
    root->right->right->left = new Node(18);

    /**
     *              11
     *            /   \
     *           7     15
     *          / \    / \
     *         3   9  13 19
     *                   /
     *                  18
     */

    cout << "Minimum depth = " << max_depth(root) << endl;
    return 0;
}