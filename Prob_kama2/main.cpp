#include <iostream>
using namespace std;

int main() {
    int a,n,m;

//这题错的同学请注意题目的提示“注意，测试数据不仅仅一组。也就是说，会持续输入N以及后面的a和b”，只有一次cin>>n是过不了的。
    while(cin>>n)
    {    while(n--)
        {
            while(cin>>m)
            {
                int sum = 0;
                while(m--)
                {
                    cin>>a;
                    sum+=a;
                }
                cout << sum<<endl<<endl;
            }

        }
    }
    return 0;
}