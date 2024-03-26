#include <iostream>


struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() :val(0),left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool compare_two_node(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr) return true;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right != nullptr) return false;
        else if (left->val != right->val) return false;
        else
            return compare_two_node(left->left,right->right)&&compare_two_node(left->right,right->left);
    }


    bool isSymmetric(TreeNode* root) {
        return compare_two_node(root->left,root->right);
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
