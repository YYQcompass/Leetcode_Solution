#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //获取 obstacleGrid 的size
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // 如果 obstacleGrid 为空，返回0
        if (m == 0 || n == 0) {
            return 0;
        }
        //如果 obstacleGrid 在0，0和m，n的元素为1，表示永远走不到终点
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        //初始化dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m && obstacleGrid[i][0]==0; i++)
                dp[i][0] = 1;

        for(int j = 0; j < n && obstacleGrid[0][j]==0; j++)
                dp[0][j] = 1;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // dp递推公式
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] =dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


int main() {
    vector<vector<int>> obstacleGrid = {{0,0},{1,1},{0,0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
