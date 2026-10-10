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
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(a && b){
            ListNode* node;
            if(a->val<b->val){
                node=a;
                a=a->next;
            }
            else{
                node=b;
                b=b->next;
            }
            if(head==NULL){
                head=node;
                tail=node;
            }
            else{
                tail->next=node;
                tail=tail->next;
            }
        }
        if(tail){
            tail->next=a?a:b;
        } 
        else{
            head=a?a:b;
        }
        return head;
    }
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid=getMid(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* left=sortList(head);
        right=sortList(right);
        return merge(left,right);
    }
};