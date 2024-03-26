#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int original_MTs = count(str.begin(),str.end(),'M')+ count(str.begin(),str.end(),'T');
    int max_MTs = min(n-original_MTs,k)+original_MTs;
    cout<<max_MTs;
    return 0;
}
