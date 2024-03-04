#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 0) return 0;
////        int dp[n]; //这里n是变化的，C++不支持定义这种变长数组
//        vector<int> dp(n);
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//        for(int i = 2; i < n; i++)
//        {
//            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
//        }
//        return dp[n-1];
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
