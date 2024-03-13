#include <iostream>

struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
   };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        // 定义left和 right 指针
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy->next;
        ListNode* right = left->next;
        ListNode* previous = dummy;
        while(right)
        {
            ListNode *temp = right->next;
            right->next = left;
            left->next = temp;
            previous->next = right;
            previous = left;
            left = temp;
            if (temp==nullptr)
                break;
            right = temp->next;
        }
        return dummy->next;
    }
};


int main() {
    Solution solution;
    // 建立一个[1,2,3,4]的链表
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = solution.swapPairs(head);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
