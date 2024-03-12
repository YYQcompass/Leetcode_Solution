#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 使用滑动窗口算法
        int result = 0;
        int left = 0;
        // 建立一个哈希表来存放符合只有两种数值类型的窗口中的数和出现的次数
        unordered_map<int, int> fruitCount;
        // 滑动窗口的常见构建方式就是for管right，一直加，while中管left，不符合的窗口就要left++，直到窗口符合了。
        for(int right = 0; right < fruits.size(); ++right)
        {
            // 将当前 fruits[right]加入哈希表中，其对应的次数加1
            fruitCount[fruits[right]]++;
            // 如果当前窗口中的数值类型数量大于2，那么就将窗口左边的数值类型从哈希表中删除，其对应的次数减1
            while(fruitCount.size() > 2)
            {
                fruitCount[fruits[left]]--;
                if(fruitCount[fruits[left]] == 0)
                {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }
            // 运行到这的窗口都是符合只有两种数值类型的窗口，计算当前窗口的长度，更新最大值result。
            result = max(result, right - left + 1);
        }
        return result;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
