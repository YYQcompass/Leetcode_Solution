#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 分别建立哈希表
        unordered_map<int, int> map1, map2;
        for (int i = 0; i < nums1.size(); i++) {
            map1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            map2[nums2[i]]++;
        }
        vector<int> res;
        for(auto it = map1.begin(); it != map1.end(); it++)
        {
            if(map2.find(it->first) != map2.end())
            {
                int count = min(it->second, map2[it->first]);
                for(int i = 0; i < count; i++)
                {
                    res.push_back(it->first);
                }
            }
        }
        return res;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
