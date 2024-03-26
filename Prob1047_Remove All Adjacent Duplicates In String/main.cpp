#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



int main() {
    Solution s;
    cout << s.removeDuplicates("abbaca") << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
