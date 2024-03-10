#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        // 定义dp数组dp[i]，表示将i这个数拆成两个以上的数，能组成的最大乘积
        vector<int> dp(n + 1, 0);
        // dp[0] 和 dp[1] 并没有意义，因为拆不了了
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j),j*dp[i-j]));
            }
        }
        return dp[n];
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
