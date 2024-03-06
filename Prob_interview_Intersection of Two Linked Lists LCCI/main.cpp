#include <iostream>
#include <algorithm>
using namespace std;



struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 1. find the length of the two lists
        // 2. 让长的链表先走a-b步，然后两个链表同时走，如果相遇，就是交点
        ListNode *p1 = headA, *p2 = headB;
        int len1 = 0, len2 = 0;
        while (p1) {
            len1++;
            p1 = p1->next;
        }
        while (p2) {
            len2++;
            p2 = p2->next;
        }
        // 通过swap函数保证p1是长的
        p1 = headA; p2 = headB;
        if (len1 < len2) {
            swap(p1, p2);
            swap(len1, len2);
        }
        // 让长的链表先走a-b步
        int gap = len1 - len2;
        while(gap--)
        {
            p1 = p1->next;
        }
        //此时两个指针同时走，如果相遇，就是交点
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;

    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
