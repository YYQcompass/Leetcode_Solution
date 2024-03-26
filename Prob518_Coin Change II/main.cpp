#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 错误解法，使用跟零钱兑换1题那样的一维dp数组，会存在没有去重的情况。正确做法是应该使用二维的dp数组。
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        dp[0] = 0;
        for(int i=1; i<=amount; i++)
        {
            for(auto coin:coins)
            {
                if(coin == i) dp[i]+=1;
                else if(coin < i && dp[i-coin]!=0)
                {
                    dp[i] += dp[i-coin];
                }
            }
        }
        return dp[amount];
    }
    int Change(vector<int>& coins, int& amount) {

        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for (int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][amount];
    }
};
int main() {
    // 输入coins = {1,2,5} amount = 5 进行测试
    vector<int> coins = {1,2,5};int amount = 5;
    Solution s;
    std::cout << s.Change(coins,amount) << std::endl;
    return 0;
}
