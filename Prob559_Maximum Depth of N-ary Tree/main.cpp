#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        if(root->children.empty())
        {
            return 1;
        }
        else
        {
            int depth = INT_MIN;
            for (auto child : root->children)
            {
                depth = max(depth, maxDepth(child));
            }
            return depth + 1;
        }
    }


    int maxDepth2(Node* root) {
        if (root == nullptr) return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()){
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                for(int i=0;i<node->children.size();i++){
                    q.push(node->children[i]);
                }
            }
        }
        return depth;
    }

};

int main() {
    // 输入[1,null,3,2,4,null,5,6]
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    cout << Solution().maxDepth(root) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
