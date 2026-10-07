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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* beforeslow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            beforeslow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        beforeslow->next=slow->next;
        delete slow;
        return head;
    }
};