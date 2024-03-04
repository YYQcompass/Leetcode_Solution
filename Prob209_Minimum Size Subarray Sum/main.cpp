#include <iostream>
#include <vector>
using namespace std;
/*
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
 * 并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 定义循环变量i 和 j，i 表示滑动窗口的左边界，j 表示滑动窗口的右边界
        int i = 0, j = 0, sum = 0, ans = INT_MAX;
        // sum 表示滑动窗口内元素的和
        for(j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while(sum >= target)
            {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
        }

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
