#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;


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
    vector<int> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(i==size-1)
                {
                    level.push_back(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return level;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
