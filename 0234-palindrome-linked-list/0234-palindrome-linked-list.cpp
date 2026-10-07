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
private:
    ListNode* reverse(ListNode* root){
        ListNode* prev=NULL;
        ListNode* curr=root;
        while(curr){
            ListNode* nextN=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextN;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revList=reverse(slow);
        while(revList){
            if(head->val!=revList->val){
                return false;
            }
            head=head->next;
            revList=revList->next;
        }
        return true;
    }
};