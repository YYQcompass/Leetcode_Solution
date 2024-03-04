#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //使用 unordered_set 来分别存储两个数组中的元素 unordered_set的一个特殊功能是去重
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());
        vector<int> results;
        // 遍历set2中的元素
        for(auto it=set2.begin();it!=set2.end();it++)
        {
            if(set1.find(*it)!=set1.end())
            {
                results.push_back(*it);
            }
        }
        return results;
    }
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        //只需要使用一个 unordered_set 来存nums1，再用一个 unordered_set 来存去重的results
        // 上面这样做的好处是可以节省由于建立hash表所引入的时间
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> results;
        // 遍历 nums2 中的元素
        for(auto num : nums2)
        {
            if(set1.find(num)!=set1.end())
            {
                results.insert(num);
            }
        }
        return vector<int>(results.begin(),results.end());
    }
};
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
