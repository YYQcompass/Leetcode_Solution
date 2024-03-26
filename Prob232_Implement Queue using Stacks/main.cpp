#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
private:
    stack<int> in;
    stack<int> out;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
