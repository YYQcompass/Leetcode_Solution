#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,q,L,R;
    long sum_certain = 0;
    long num_uncertain = 0;
    cin>>n>>q;
    vector<int> vec(n);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
        if(vec[i]==0)
        {
            num_uncertain++;
        }
        else sum_certain+=vec[i];
    }
    while(q--)
    {
        cin>>L>>R;
        cout<< sum_certain+num_uncertain*L<<' '<<sum_certain+num_uncertain*R<<endl;
    }
    return 0;
}
