#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = stk.top();stk.pop();
                int b = stk.top();stk.pop();
                stk.push(a+b);
            } else if (tokens[i] == "-") {
                int a = stk.top();stk.pop();
                int b = stk.top();stk.pop();
                stk.push(b-a);
            } else if (tokens[i] == "*") {
                int a = stk.top();stk.pop();
                int b = stk.top();stk.pop();
                stk.push(b*a);
            } else if (tokens[i] == "/") {
                int a = stk.top();stk.pop();
                int b = stk.top();stk.pop();
                stk.push(b/a);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
