#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //定义快慢两个指针，快指针遍历整个数组，慢指针指向非0元素，当快指针指向非0的元素就把该值交换
        int slow = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0) {
                nums[slow] = nums[i];
                if(slow != i)
                    nums[i] = 0;
                slow++;
            }
    }
    void moveZeroes1(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if(nums[fast] != 0)
            {
                nums[slow++] = nums[fast];//先赋值，再加加
            }
        }
        for (int i = slow; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
