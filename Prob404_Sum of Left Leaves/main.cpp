#include <iostream>


struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traverse(TreeNode* node, int& sum) {
        if(node->left == NULL && node->right == NULL) return;
        if (node->left)
        {
            if(node->left->left == NULL && node->left->right == NULL)
            {
                sum += node->left->val;
                return;
            }
            else{
                traverse(node->left, sum);
            }
        }
        if (node->right)
        {
            traverse(node->right, sum);
        }

    }
    int sumOfLeftLeaves2(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        traverse(root, sum);
        return sum;

    }


    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        int leftsum = sumOfLeftLeaves(root->left);
        int rightsum = sumOfLeftLeaves(root->right);
        if(root->left && root->left->left == NULL && root->left->right == NULL)
            leftsum += root->left->val;
        return leftsum + rightsum;

    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
