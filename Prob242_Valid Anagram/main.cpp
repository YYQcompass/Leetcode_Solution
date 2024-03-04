#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 首先排除s和t长度不相等的情况
        if (s.length() != t.length()) {
            return false;
        }
        // 将字符串s用unordered_set建立hash
        unordered_map<char, int> map;
        for(auto c : s)
        {
            map[c]+=1;
        }
        for(auto c : t)
        {
            map[c]-=1;
        }
        // 遍历map，如果有值不为0，说明s和t不相等
        for(auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second != 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
