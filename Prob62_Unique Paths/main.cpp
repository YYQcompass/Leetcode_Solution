#include <iostream>




class Solution {
public:
    int uniquePaths(int m, int n) {
        //定义一个二维dp数组并全部初始化为0
        int dp[m][n];
        //dp数组的第一行和第一列初始化为1
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // dp递推公式
                dp[i][j] =dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
