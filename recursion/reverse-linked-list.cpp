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
    ListNode* reverseList(ListNode* head) {
        ListNode*CurrNode=head;
        ListNode*PreNode=NULL;
        ListNode*NextNode=NULL;
        while(CurrNode!=NULL){
            NextNode=CurrNode->next;
            CurrNode->next=PreNode;
            PreNode=CurrNode;
            CurrNode=NextNode;
        }
        return PreNode;
    }
};