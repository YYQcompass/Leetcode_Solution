#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


/*
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k) // 每次增加2k步长
        {
            // 如果当前i的位置加k之后不超过s的size，那可以翻转k个字符
            if(i + k < s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 如果当前i的位置加k之后超过s的size，那只能翻转剩余的字符
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
