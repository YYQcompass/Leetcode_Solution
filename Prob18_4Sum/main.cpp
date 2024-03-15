#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                long long sum12 = nums[i] + nums[j];
                while (left < right) {
                    long long sum34 = nums[left] + nums[right];
                    if (sum34 < target-sum12) {
                        left++;
                    } else if(sum34 > target-sum12) {
                        right--;
                    }
                    else {
                        res.push_back({nums[i],nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        left++;right--;
                    }

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
