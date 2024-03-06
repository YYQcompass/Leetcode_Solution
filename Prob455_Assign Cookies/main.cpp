#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
 * 但是，每个孩子最多只能给一块饼干。
 * 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
 * 并且每块饼干 j，都有一个尺寸 s[j] 。
 * 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
 * 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /*
         * 本题使用贪心算法来求解，尽可能的使用小的饼干来满足小胃口的孩子，每次都是想办法满足最小胃口的那个孩子*/
        // 由于后面要从小到大进行一个遍历，所以需要对两个数组进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 外层循环遍历孩子数组
        int res = 0; int j=0;
        for (int i=0; i<g.size(); i++)
        {
            // 如果当前孩子满足了，就将当前孩子从孩子数组中删除，同时将当前饼干从饼干数组中删除
            while( j<s.size() && g[i] > s[j])
            {
                j++;
            }
            if (j<s.size() && g[i] <= s[j])
            {
                res++;
                j++;
            }
        }
        return res;
    }
};






int main() {
    // g={1,2,3}; s={1,1}
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout<<Solution().findContentChildren(g, s)<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
