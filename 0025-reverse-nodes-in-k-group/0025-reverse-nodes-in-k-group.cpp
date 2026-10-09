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
    ListNode* findKth(ListNode* head,int k){
        k--;
        while(head!=NULL && k>0){
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverse(ListNode* temp){
        ListNode* prev=NULL;
        ListNode* curr=temp;
        while(curr){
            ListNode* nextN=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextN;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp){
            ListNode* kthnode=findKth(temp,k);
            if(kthnode==NULL){
                if(prev){
                    prev->next=temp;
                    break;
                }
            }
            ListNode* nextNode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prev->next=kthnode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};