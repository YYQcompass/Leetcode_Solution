#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 先获取s的size 若为单数肯定false
        int size = s.size();
        if (size % 2 != 0) {
            return false;
        }
        stack<char> st;
        for (int i = 0; i < size; i++) {
            // 只有左括号会被放入栈中等待匹配
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else // 当前 s[i] 为右括号
            {
                if(st.empty())
                    return false;
                else
                {
                    char top = st.top();
                    st.pop();
                    if(top == '(' && s[i] != ')')
                        return false;
                    else if(top == '[' && s[i] != ']')
                        return false;
                    else if(top == '{' && s[i] != '}')
                        return false;
                }
            }
        }
        return st.empty(); // 这里不能直接
    }

    bool isValid1(string s) {
        // 先获取s的size 若为单数肯定false
        int size = s.size();
        if (size % 2 != 0) {
            return false;
        }
        stack<char> st;

        for (int i = 0; i < size; i++) {
            if(st.empty())
                st.push(s[i]);
            else
            {
                if(s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    char top = st.top();
                    st.pop();
                    if(top == '(' && s[i] != ')')
                        return false;
                    else if(top == '[' && s[i] != ']')
                        return false;
                    else if(top == '{' && s[i] != '}')
                        return false;
                }
                else
                    st.push(s[i]);
            }
        }
        return st.empty(); // 这里不能直接
    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
