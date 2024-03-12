#include <iostream>
#include <vector>
using namespace std;
/* 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 */
class Solution {
public:
    int mySqrt1(int x) {
        // 建立一个从1 的 平方到x 的平方的数组
        vector<int> nums(x + 1,0);
        for (int i = 1; i <= nums.size()-1; i++) {
            nums[i] = i * i;
        }
        // 二分查找
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) // 左闭右闭区间的写法, 当left==right，区间[left, right]依然有效，所以用 <=
        {
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2,两个int 类型的数值相加 是有可能超过int类型本身范围的
            if(nums[middle] > x)
            {
                right = middle-1;// target 在左区间，所以[left, middle - 1]
            }
            else if(nums[middle] < x)
            {
                left = middle+1;// target 在右区间，所以[middle + 1, right]
            }
            else return middle; // nums[middle] == target

        }
        // 当目标不在nums中时，left此时一定是大于right的，所以left就是插入的位置
        return right;
    }

    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        // 初始化二分查找的左右边界
        int left = 1, right = x;

        while (left <= right) {
            long middle = left + ((right - left) / 2);

            // 计算中间值的平方，并与目标值比较
            if (middle * middle > x) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (middle * middle < x) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else {
                return middle; // 找到正确答案，nums[middle] == target
            }
        }

        // 当循环结束时，left是大于right的，此时right即为不超过x的最大整数平方根
        return right;
    }

};






int main() {
    Solution s;
    std::cout << s.mySqrt(8) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
