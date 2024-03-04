#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if(nums[fast] != val)
            {
                nums[slow++] = nums[fast];//先赋值，再加加
            }
        }
        return slow;
    }
};

int main() {
    int a[] = {-1,0,3,5,9,12};
    int val = 3;
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    cout << solution.removeElement(nums,val) << endl;
}