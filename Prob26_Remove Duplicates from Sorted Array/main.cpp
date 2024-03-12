#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val = nums[0];
        int slow = 1;
        for (int fast = 1; fast < nums.size(); ++fast) {
            if(nums[fast] == val)
            {
                continue;
            }
            else
            {
                nums[slow++] = nums[fast];//先赋值，再加加
                val = nums[fast];
            }
        }
        return slow;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
