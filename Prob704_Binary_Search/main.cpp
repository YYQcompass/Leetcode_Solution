#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Binary_Search(vector<int>& nums, int target) {
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
        return -1;
    }
};

int main() {
    int a[] = {-1,0,3,5,9,12};
    int target = 9;
    //创建一个nums的std::vector<int>容器，并用数组a的元素去初始化它。
    // * a 是数组的起始地址，即第一个元素的地址。
    // * sizeof(a) / sizeof(int) 是计算数组a的大小，即数组a的元素个数。
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    cout << solution.Binary_Search(nums,target) << endl;
}