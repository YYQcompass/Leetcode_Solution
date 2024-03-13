#include <iostream>

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 定义快慢两个指针，快指针每次走两步，慢指针每次走一步
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                // 快指针走到相遇点，慢指针从头走到相遇点
                slow = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
