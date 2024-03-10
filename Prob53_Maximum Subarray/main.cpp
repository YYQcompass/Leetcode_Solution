#include <iostream>
#include <vector>
using namespace std;
/*
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组是数组中的一个连续部分。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 本题目我们采用贪心算法的思路来做，当连续子数组的和小于0时，就舍弃掉这个连续子数组，因为这个连续子数组的和肯定比不包含这个连续子数组的和要小。
        int sum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // 下面代码的顺序很有讲究
//            if (sum < 0) {
//                sum = 0;
//            }
//            maxSum = max(maxSum, sum);
            maxSum = max(maxSum, sum)      ;
            if (sum < 0) {
                sum = 0;
            }

        }
        return maxSum;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
