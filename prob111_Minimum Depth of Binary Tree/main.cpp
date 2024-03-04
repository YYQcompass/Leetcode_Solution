#include <iostream>
#include <queue>
#include <vector>
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
    int minDepth(TreeNode* root) {
        if (!root) return 0; //如果root直接为空，那就直接返回空vector
        int depth = 0;
        queue<TreeNode *> q; //初始化一个空队列用于存放节点
        q.push(root); //将根节点放入队列
        while(!q.empty())
        {
            int size = q.size();
            depth++;
            for(int i = 0; i < size; i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
                if (!frontNode->left && !frontNode->right)
                    return depth;
            }
        }
        return depth;
    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
