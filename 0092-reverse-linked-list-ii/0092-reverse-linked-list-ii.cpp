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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* newNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newNode;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) return head;
        int count=2;
        ListNode* temp1=NULL;
        ListNode* leftNode=head;
        for(int i=1;i<left;i++){
            temp1=leftNode;
            leftNode=leftNode->next;
        }
        ListNode* temp2=leftNode;
        for(int i=left;i<right;i++){
            temp2=temp2->next;
        }
        ListNode* temp3=temp2->next;
        temp2->next=NULL;
        ListNode* rev=reverse(leftNode);
        if(temp1!=NULL) temp1->next=rev;
        else head=rev;
        while(rev->next!=NULL){
            rev=rev->next;
        }
        rev->next=temp3;
        return head;
    }
};