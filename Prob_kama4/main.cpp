#include <iostream>
using namespace std;
// 这道题要想到n个数字的相加并不需要定义n个变量，用一个变量不断的累加就好。


int main() {
    int n,a;

    while(cin>>n){
        if(n==0) return 0;
        else
        {
            int sum = 0;
            while(n--)
            {
                cin>>a;
                sum+=a;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
