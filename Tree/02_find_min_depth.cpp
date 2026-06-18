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
int minDepth(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) return 1 + minDepth(root->right);
    if (root->right == nullptr) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = new Node(3);
    Node* n1 = new Node(9);
    Node* n2 = new Node(20);
    Node* n3 = new Node(15);
    Node* n4 = new Node(7);

    root->left = n1, root->right = n2;
    n2->left = n3, n2->right = n4;

    /**
     *         3
     *        / \
     *       9   20
     *          /  \
     *         15   7
     */

    cout << "Minimum depth = " << minDepth(root) << endl;
    return 0;
}