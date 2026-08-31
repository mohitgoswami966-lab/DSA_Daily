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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        int idx=1;
        int firstCritical=-1;
        int lastCritical=-1;
        int minDis=INT_MAX;
        while(curr->next){
            ListNode* next=curr->next;
            bool isMin=curr->val<prev->val && curr->val<next->val;
            bool isMax=curr->val>prev->val && curr->val>next->val;
            if(isMax||isMin){
                if(lastCritical==-1){
                    firstCritical=idx;
                }
                else{
                    minDis=min(minDis,idx-lastCritical);
                }
                lastCritical=idx;
            }
            prev=curr;
            curr=next;
            idx++;
        }
        if(lastCritical==-1||firstCritical==lastCritical) return{-1,-1};
        int maxDis=lastCritical-firstCritical;
        return {minDis,maxDis};
    }
};