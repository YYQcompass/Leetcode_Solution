#include <iostream>
#include <vector>
using namespace std;
/* 题意
 * 现有一个长度为n的数组a和m个区间。
 * 你可以选择任意个区间，选择的区间不能相交。如果选择一个区间[l,r]。那么可以获得∑(i=1,r)ai的分数。
 * 请你计算出你可以获得的最大分数。
 * 请注意，如果区间右端点在数组的范围之外，则该区间不可选取。
 * 假设两个区间分别是[l1,r1]和[l2,r2]，如果它们满足l1<=l2<=r1或l2<=r1<=r2，则认为这两个区间相交。
*/

/* 输入描述
 * 第1行包含两个整数n和m，分别表示数组a的长度和区间数。
 * 第2行包含n个整数ai，表示数组a中的元素。
 * 第3行到第m+2行，每行包含两个整数li和ri，表示第i个区间[li,ri]。
 * */


class Solution {
public:
    int maxScore(vector<int>& a, vector<vector<int>>& child) {

    }
};






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
