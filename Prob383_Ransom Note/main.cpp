#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (auto c: magazine)
        {
            map[c]++;
        }
        for (auto c: ransomNote)
        {
            if (map[c] == 0) // 因为magazine中的字母是不能重复使用的，所以不能用find。//map[c] == 0 要么就是没有这个字母，要么就是这个字母之前用过，现在不够用了，那也是不行。
            {
                return false;
            }
            map[c]--;
        }
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
