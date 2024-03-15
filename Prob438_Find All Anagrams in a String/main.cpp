#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。


class Solution {
public:
    bool isAnagram(string& sub, unordered_map<char, int> map) {
        for(auto c: sub)
        {
            if(map[c] == 0)
                return false;
            map[c]--;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return {};
        unordered_map<char, int> map;
        for (int i = 0; i < p.size(); i++) {
            map[p[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < s.size() - p.size()+1; ) {
            string sub = s.substr(i, p.size());
            if (isAnagram(sub, map))
            {
                res.push_back(i);
                while (s[i] == s[i+p.size()])
                {
                    res.push_back(++i);
                }
                i=i+2;
            }
            else
                i++;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> result =  s.findAnagrams("acdcaeccde", "c") ;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
