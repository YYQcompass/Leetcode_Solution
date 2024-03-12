#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int deletebackspace(string &s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); ++fast) {
            if(s[fast] != '#')
            {
                s[slow++] = s[fast];//先赋值，再加加
            }
            else
                if (slow > 0) slow--;
        }
        return slow;
    }
    bool backspaceCompare(string s, string t) {
        int m = deletebackspace(s);
        int n = deletebackspace(t);
        return m == n && s.substr(0, m) == t.substr(0, n);
    }
};


int main() {
    Solution s;
    cout << s.backspaceCompare("a##c", "#a#c") << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
