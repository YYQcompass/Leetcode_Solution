#include <iostream>
#include <vector>
using namespace std;
/*有一堆石头，用整数数组stones表示。其中stones[i]表示第i块石头的重量。
每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为x和y,且×<=y。那么粉碎的可能结果如下：
如果×=y,那么两块石头都会被完全粉碎；
如果x!=y,那么重量为x的石头将会完全粉碎，而重量为y的石头新重量为y-x。
最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩刺下，就返回0。*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 这道题目的关键在于能想到说尽可能的把整个石头堆分成重量尽可能相同的两堆，类似从一个数组中找到一个和尽量为石头总和一半的子石头堆
        // 这样两堆石头相减就会小
        // 因此首先计算石头的总重量
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        // 按照前向顺序遍历物品 再按后向顺序遍历背包
        for (int i = 0; i < stones.size(); i++) { // 遍历物品
            for (int j = target; j >= stones[i]; j--) { // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];

    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
