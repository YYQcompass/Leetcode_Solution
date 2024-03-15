#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = sortString(strs[i]);
            map[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
