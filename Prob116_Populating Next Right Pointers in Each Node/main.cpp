#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for (int i=0;i<size;i++)
            {
                Node* curnode = que.front();
                que.pop();
                if(i == size-1) curnode->next = nullptr;
                else
                {
                    Node* nextnode = que.front();
                    curnode->next = nextnode;
                }
                if(curnode->left) que.push(curnode->left);
                if(curnode->right) que.push(curnode->right);
            }
        }
        return root;
    }

};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
