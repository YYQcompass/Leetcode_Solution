#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 遍历nums1和nums2两两之间的和，存到一个 unordered_map 中
        unordered_map<int,int> sum12;
        int result = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                sum12[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                if(sum12.find(-nums3[i] - nums4[j])!= sum12.end())
                {
                    result += sum12[-nums3[i] - nums4[j]];
                }
            }
        }
        return result;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
