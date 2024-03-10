#include <iostream>
#include "vector"
using namespace std;
// 输入正整数n，求1...n 可以组成的二叉搜索树的个数


class Solution {
public:
    int numTrees(int n) {
        //定义dp数组，dp[i]表示1...i 可以组成的二叉搜索树的个数
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
