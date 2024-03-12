#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;

        // 初始化二分查找的左右边界
        int left = 1, right = num;

        while (left <= right) {
            long middle = left + ((right - left) / 2);

            // 计算中间值的平方，并与目标值比较
            if (middle * middle > num) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (middle * middle < num) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else {
                return true; // 找到正确答案，nums[middle] == target
            }
        }
        return false;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
