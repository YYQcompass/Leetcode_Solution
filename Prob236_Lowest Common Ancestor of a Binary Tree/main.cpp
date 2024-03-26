#include <iostream>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root==p||root==q) return root;
        TreeNode* left_have_qp = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_have_qp = lowestCommonAncestor(root->right,p,q);
        if(!left_have_qp&&!right_have_qp) return nullptr;
        if(left_have_qp&&!right_have_qp) return left_have_qp;
        if(!left_have_qp&&right_have_qp) return right_have_qp;
        if(left_have_qp&&right_have_qp) return root;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
