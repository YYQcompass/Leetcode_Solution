#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
/*      给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，
        且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。*/
        vector<vector<int>> Matrix(n, vector<int>(n, 0));
        // 不需要算n方，循环设计的号 再逐步+1，最终就是n方，每个大循环里面包含4条边的小循环。
        int startX = 0; int startY = 0; int offset = 1;int value = 1;
        for(int m = 0; m<n/2; m++)
        {
            int i=startX,j=startY;
            //上边，从左到右，左闭右开
            for (; j<n-offset; j++)
            {
                Matrix[i][j] = value++;
            }
            // 右边，从上到下，上闭下开
            for (; i<n-offset; i++)
            {
                Matrix[i][j] = value++;
            }
            // 下边，从右到左，右闭左开
            for (; j>startY; j--)
            {
                Matrix[i][j] = value++;
            }
            // 左边，从下到上，下闭上开
            for (; i>startX; i--)
            {
                Matrix[i][j] = value++;
            }
            startX++; startY++; offset++;
        }

        // if n为奇数
        if(n%2)
        {
            Matrix[startX][startY] = value;
        }
        return Matrix;

    }
};


int main() {
    Solution s;
    vector<vector<int>> result = s.generateMatrix(3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
