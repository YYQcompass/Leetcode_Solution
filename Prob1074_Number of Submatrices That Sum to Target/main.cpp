#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int n = matrix.size();
        vector<vector<int>> diffMatrix(n+1,vector<int>(n+1));
        for (int i = 1; i<=n;i++)
        {
            for (int j = 1; j<=n;j++)
            {
                diffMatrix[i][j]=diffMatrix[i-1][j]+diffMatrix[i][j-1]-diffMatrix[i-1][j-1]+matrix[i-1][j-1];
            }
        }

        for (int k = 1;k<=n;k++) // size 大小为k
        {

            // 前缀和解法
            for(int i1=0;i1<=n-k;i1++)
            {
                for(int j1=0;j1<=n-k;j1++){
                    int i2 = i1+k;
                    int j2 = j1+k;
                    int diff = diffMatrix[i2][j2] - diffMatrix[i1][j2] -diffMatrix[i2][j1]+diffMatrix[i1][j1];
                    if (diff==target)
                    {
                        count++;
                    }
                }
            }

        }
        return count;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
