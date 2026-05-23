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
    void reorderList(ListNode* head) {
        if (!head)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = NULL;
        ListNode* nextp = NULL;
        while (curr != NULL) {
            nextp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextp;
        }
        ListNode* first = head;
        curr = prev;
        while (curr != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = curr->next;
            first->next = curr;
            curr->next = temp1;
            first = temp1;
            curr = temp2;
        }
    }
};