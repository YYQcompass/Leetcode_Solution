#include <iostream>
#include <queue>
using namespace std;
class MyStack {
public:
    queue<int> main_q;
    queue<int> bk_q;
    MyStack() {

    }

    void push(int x) {
        main_q.push(x);
    }

    int pop() {
        int size = main_q.size();
        size--;
        while(size--)
        {
            bk_q.push(main_q.front());
            main_q.pop();
        }
        int ret = main_q.front(); main_q.pop();
        while(!bk_q.empty())
        {
            main_q.push(bk_q.front());
            bk_q.pop();
        }
        return ret;
    }

    int top() {
        int size = main_q.size();
        size--;
        while(size--)
        {
            bk_q.push(main_q.front());
            main_q.pop();
        }
        int ret = main_q.front(); main_q.pop();bk_q.push(ret);
        while(!bk_q.empty())
        {
            main_q.push(bk_q.front());
            bk_q.pop();
        }
        return ret;
    }

    bool empty() {
        return main_q.empty();
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
