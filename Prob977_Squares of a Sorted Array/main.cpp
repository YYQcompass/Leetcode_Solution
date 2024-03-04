#include <iostream>
#include <vector>
using namespace std;
/*给你一个按 非递减顺序 排序的整数数组 nums，
 * 返回 每个数字的平方 组成的新数组，
 * 要求也按 非递减顺序 排序。*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //当然可以先全部平方然后再sort一下，但这明显不是本题设置的考察点
        // 本题强调了 nums 为有序的，所以最大的数的平方一定是在数组的左右两边的位置，越靠近中心的数其平方越小
        int left = 0, right = nums.size() - 1;
        vector<int> res(nums.size());
        for (int i = nums.size()-1; i > -1; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;




    }
};






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
