#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        //使用双指针
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
