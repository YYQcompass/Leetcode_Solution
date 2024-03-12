#include <iostream>
#include <vector>
using namespace std;

/*
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
 * 找出给定目标值在数组中的开始位置和结束位置。
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 首先排除掉target小于nums的最小值和大于nums的最大值的情况 nums为空的情况
        if (target < nums[0] || target > nums[nums.size() - 1] ||nums.empty()) {
            return {-1, -1};
        }

        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2)
        {
            return {-1, -1};
        }
        else
        {
            return {leftBorder, rightBorder};
        }

    }
private:
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int Right_Boarder = -2;
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
            else
            { // nums[middle] == target
                left = middle+1;
                Right_Boarder = middle;
            }
        }
        return Right_Boarder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        // 二分查找找寻range的左边界
        int left = 0;
        int right = nums.size() - 1;
        int Left_Boarder = -2;
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
            else
            { // nums[middle] == target
                right = middle-1; // 这里必须减1，让区间不断变小 不然会出现死循环导致运行超时
                Left_Boarder = middle;
            }
        }
        return Left_Boarder;

    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
