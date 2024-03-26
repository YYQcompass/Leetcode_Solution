#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int & ai:nums)
        cin >> ai;

    // 初始化前缀和数组
    vector<int> pre2(n+1,0),pre5(n+1,0);
    for (int i = 0;i<n;++i){
        int num =  nums[i];
        while(num %2 == 0)
        {
            num/=2;
            pre2[i+1]++;
        }
        while(num %5 == 0)
        {
            num/=5;
            pre5[i+1]++;
        }
    }

    // 计算前缀和
    for(int i = 1;i<=n; ++i)
    {
        pre2[i] += pre2[i-1];
        pre5[i] += pre5[i-1];
    }

    int count = 0;
    for(int L=0;L<n;++L)
    {
        for(int R=L+1;R<=n;++R)
        {
            if(pre2[n]-pre2[R]+pre2[L]>=k && pre5[n]-pre5[R]+pre5[L]>=k)
            {count++;}
        }
    }
    cout<<count<<endl;

    return 0;
}
