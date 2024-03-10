#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    void backtracking(int n, int k, int startindex, vector<vector<int>>& res, vector<int>& cur)
    {
        if(cur.size()==k)
        {
            int sum = accumulate(cur.begin(), cur.end(), 0);
            if (sum==n)
            {
                res.push_back(cur);
                return;
            }

        }
        for(int i=startindex;i<=9;i++)
        {
            cur.push_back(i);
            backtracking(n,k,i+1,res,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res; vector<int> cur;
        backtracking(n,k,1,res,cur);
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
