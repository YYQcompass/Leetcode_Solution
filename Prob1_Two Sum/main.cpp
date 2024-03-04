#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 建立一个哈希表存放已经遍历过的元素
        unordered_map <int, int> map;
        //遍历数组
        for (int i = 0; i < nums.size(); i++) {
                if(map.find(target-nums[i])!=map.end()){
                    return {map[target-nums[i]], i};
                }
                else{
                    map[nums[i]]=i;
                }
            }
        //返回空数组
        return {};
        }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
