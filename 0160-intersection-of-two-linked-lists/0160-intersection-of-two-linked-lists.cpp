/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* First=headA;
        ListNode* Second=headB;
        while(First!=Second){
            First=First->next;
            Second=Second->next;
            if(First==Second) return First;
            if(First==NULL) First=headB;
            if(Second==NULL) Second=headA;
        }
        return First;
    }
};