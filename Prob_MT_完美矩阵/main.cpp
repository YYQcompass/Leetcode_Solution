#include <iostream>
#include <vector>
#include <string>
using namespace std;


void computePerfectMatrix(vector<vector<int>> &matrix,int &n, vector<int> &perfect)
{
    perfect.resize(n+1);

    // 构建二维前缀和矩阵
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
        if(k%2==0)
        {
            // 前缀和解法
            for(int i1=0;i1<=n-k;i1++)
            {
                for(int j1=0;j1<=n-k;j1++){
                    int i2 = i1+k;
                    int j2 = j1+k;
                    int diff = diffMatrix[i2][j2] - diffMatrix[i1][j2] -diffMatrix[i2][j1]+diffMatrix[i1][j1];
                    if (diff==k*k/2)
                    {
                        perfect[k]++;
                    }
                }
            }


            // 暴力解法
//            for(int x=0;x<=n-k;x++)
//            {
//                for(int y=0;y<=n-k;y++)
//                {
//                    int zeros=0,ones=0;
//                    for(int dx=0;dx<k;dx++)
//                    {
//                        for(int dy=0;dy<k;dy++)
//                        {
//                            if(matrix[x+dx][y+dy]==0)
//                            {
//                                zeros++;
//                            } else
//                            {
//                                ones++;
//                            }
//                        }
//                    }
//                    if(zeros==ones)
//                    {
//                        perfect[k]++;
//                    }
//                }
//            }
        }
        else{
            perfect[k]==0;
        }
    }
}

int main() {
    int n;
    cin>>n; //读取矩阵的大小。
    vector<vector<int>> matrix(n,vector<int>(n));

    for(int i = 0;i<n;i++)
    {
        string rowstr;
        cin>>rowstr;
        for(int j=0;j<n;j++){
         matrix[i][j]=rowstr[j]-'0';
        }
    }
    vector<int> perfect; //存储不同大小的完美子矩阵的数量
    computePerfectMatrix(matrix,n,perfect);
    for(int i = 1;i<=n;i++)
    {
        cout<<perfect[i]<<endl;
    }
}
