#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
// 自己实现一个单调队列
class myQueue {
public:
    deque<int> q;
    myQueue() {
        // Do nothing
    }
    void push(int x) {
        while(!q.empty() && q.back() < x)
        {q.pop_back();}
        q.push_back(x);
    }
    void pop(int value) {
        if(!q.empty()&& q.front() == value)
            q.pop_front();
    }
    int peek() {
        return q.front();
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        myQueue q;
        for(int i = 0; i < nums.size(); i++)
        {
            if (i<k)
            {
                q.push(nums[i]);
            }
            else
            {
                q.pop(nums[i-k]);
                q.push(nums[i]);
                ans.push_back(q.peek());
            }
        }
        return ans;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
