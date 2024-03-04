#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 本题目使用动态规划进行求解
        // 首先判断nums的长度，如果小于2，肯定不能分割
        if (nums.size() < 2) {
            return false;
        }
        // 计算数组元素和 记为sum，如果sum为奇数，肯定不能分割，如果sum为偶数，则计算数组最大元素（使用STL算法实现）
        int sum = accumulate(nums.begin(), nums.end(), 0);
        auto max_value = *max_element(nums.begin(), nums.end());
        if (sum % 2 == 1) {
            return false;
        }
        if (sum / 2 < max_value) {
            return false;
        }
        // 构建dp二维数组并统一初始化为false
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum / 2 + 1, false));
        // 初始化第一列， target 为 0，那只要所有元素都不取，dp[i][0] = true
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }
        // 第一行中j=nums[0]的元素为true
        dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= sum / 2; j++) {
                // 如果当前元素大于j，那么当前元素不能取，dp[i][j] = dp[i-1][j]
                if (nums[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // 如果当前元素小于等于j，那么当前元素可以取可以不取，
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][sum / 2];
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
