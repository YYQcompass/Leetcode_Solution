#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/* 给你一个字符串 s 、一个字符串 t 。
 * 返回 s 中涵盖 t 所有字符的最小子串。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。*/
class Solution {
public:
    bool check(unordered_map<char, int> &m, unordered_map<char, int> &n)
    {
        for (auto it = m.begin(); it != m.end(); it++) {
            if (n[it->first] < it->second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        // 建立一个哈希表统计t中的每个字符的出现次数
        unordered_map<char, int> m;
        for (auto c : t) {
            m[c]++;
        }
        // 使用滑动窗口来解决这道题
        int left = 0;
        // 再建立一个哈希表统计当前窗口中每个字符的出现次数
        unordered_map<char, int> n;
        int Len = INT_MAX,ansL = -1, ansR = -1;
        for(int right = 0; right < s.size(); right++)
        {
            if(m.find(s[right])!= m.end())
            {
                n[s[right]]++;
            }
            // 下面判断m中有的字符在n中都有，且n中出现的次数大于等于m中该字符的出现次数
            while(check(m,n))
            {
                // 符合要求，更新最小子串
                if(right - left + 1 < Len)
                {
                    Len = right - left + 1;
                    ansL = left;
                    ansR = right;
                }
                if(m.find(s[left])!= m.end())
                {
                    n[s[left]]--;
                }
                left++;
            }

        }
        return Len == INT_MAX ? "" :  s.substr(ansL, Len);
    }
};

int main() {
    Solution s;
    // s和t都是'a'
    std::cout << s.minWindow("aa", "aa") << std::endl;
    return 0;
}
