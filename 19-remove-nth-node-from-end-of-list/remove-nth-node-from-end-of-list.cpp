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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Removing the head
        if (fast == NULL) {
            return head->next;
        }

        // Maintain the gap
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete slow->next
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;

        delete delNode;

        return head;
    }
};