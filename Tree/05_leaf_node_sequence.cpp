#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

void dfs(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    if (!root->left && !root->right) ans.push_back(root->val);
    dfs(root->left, ans);
    dfs(root->right, ans);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    left->left = new TreeNode(6);
    left->right = new TreeNode(2);
    
    right->left = new TreeNode(9);
    right->right = new TreeNode(8);

    TreeNode* left_right = left->right;

    left_right->left = new TreeNode(7);
    left_right->right = new TreeNode(4);

    vector<int> arr;
    dfs(root, arr);

    for (int& x : arr) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}