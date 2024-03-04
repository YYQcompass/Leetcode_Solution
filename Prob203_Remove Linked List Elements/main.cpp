#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    // 三种构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 使用虚拟头节点，避免头节点与非头节点的判断与操作冗余
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        // 始终判断当前节点的下一个结点是否为要删除的结点，如果为要删除的结点，则删除当前结点的下一个结点，否则，当前结点后移
        while(cur != nullptr && cur->next != nullptr)
        {
            if(cur->next->val == val)
            {
                ListNode* tmp = cur->next; //保存要删除的结点的指针 用于后续释放内存
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};