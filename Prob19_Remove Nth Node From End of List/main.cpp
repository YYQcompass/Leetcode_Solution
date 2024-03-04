#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 定义一个虚拟头结点
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        // 定义快慢两个指针
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        // 快指针先移动n次
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        // 快慢指针同时移动
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // 此时slow指针指向了待删除结点的前一位
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummy->next;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
