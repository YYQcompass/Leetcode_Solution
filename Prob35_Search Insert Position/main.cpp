#include <iostream>
#include <vector>
using namespace std;
/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 你可以假设数组中无重复元素。*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 本题目的思路和二分查找那套题基本一样，唯一不同的点在于说，当目标值不存在于数组中时，找到离target最近的那个索引
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) // 左闭右闭区间的写法, 当left==right，区间[left, right]依然有效，所以用 <=
        {
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2,两个int 类型的数值相加 是有可能超过int类型本身范围的
            if(nums[middle] > target)
            {
                right = middle-1;// target 在左区间，所以[left, middle - 1]
            }
            else if(nums[middle] < target)
            {
                left = middle+1;// target 在右区间，所以[middle + 1, right]
            }
            else return middle; // nums[middle] == target

        }
        // 当目标不在nums中时，left此时一定是大于right的，所以left就是插入的位置
        return left;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
