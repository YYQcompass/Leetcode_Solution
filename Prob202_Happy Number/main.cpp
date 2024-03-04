#include <iostream>
#include <unordered_set>
using namespace std;
/*编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/
class Solution {
public:
    // 写一个算法将一个正整数替换为每个位置上的数字平方和
    int getsum(int n) {
        int sum = 0;
        // 从个位开始逐位的计算平方和并累积到sum中
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10; //使用int的整除舍弃掉最后一位数
        }
        return sum;
    }
    bool isHappy(int n) {
        // 这道题目的难点在于要能想到无限循环意味着 平方和sum的结果重复出现了，再通过哈希算法可以判断重复继而判断快乐数
        unordered_set<int> sumset;
        while(true)
        {
            int sum = getsum(n);
            if(sum == 1)
                return true;
            else if(sumset.find(sum) != sumset.end())
                return false;
            else
                sumset.insert(sum);
            n = sum;
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
