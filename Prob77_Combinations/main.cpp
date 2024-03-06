#include <iostream>
#include <vector>
using namespace std;


/*给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 你可以按 任何顺序 返回答案。*/

// 本题目主要考察回溯算法
class Solution {
public:
    void backtracking(int n, int k, int startindex, vector<vector<int>>& res, vector<int>& cur)
    {
        if(cur.size()==k)
        {
            res.push_back(cur);
            return;
        }
        for(int i=startindex;i<=n;i++)
        {
            cur.push_back(i);
            backtracking(n,k,i+1,res,cur);
            cur.pop_back();
        }
    }
    void backtracking1(int n, int k, int startindex, vector<vector<int>>& res, vector<int>& cur)
    {
        if(cur.size()==k)
        {
            res.push_back(cur);
            return;
        }
        //如果剩下的数不可能凑出k，则不需要回溯了，做相应的剪枝
        for(int i=startindex;i<=n && n-i+1>=k-cur.size();i++)
        {
            cur.push_back(i);
            backtracking(n,k,i+1,res,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; vector<int> cur;
        backtracking(n,k,1,res,cur);
        return res;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
