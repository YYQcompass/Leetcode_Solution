#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int fib2(int n) {
        if (n <= 1) return n;
        int dp[2] = {0, 1};

        for (int i = 2; i <= n; ++i)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
