#include <iostream>
#include <vector>
#include <string>
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
    void traverse(TreeNode* root, vector<int>& path, vector<string>& res) {
        path.push_back(root->val); //中
        if(root->left == nullptr && root->right == nullptr)
        {
            // 这里要将path转为字符串并添加到res中
            string s;
            for(int i = 0; i < path.size()-1; i++)
                s += to_string(path[i]) + "->";
            s += to_string(path[path.size()-1]);
            res.push_back(s);
        }
        if(root->left){
            traverse(root->left, path, res);
            path.pop_back();
        }
        if(root->right){
            traverse(root->right, path, res);
            path.pop_back();
        }
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr) return res;
        vector<int> path;
        traverse(root, path, res);
        return res;
    }
};



int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    s.binaryTreePaths(root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
