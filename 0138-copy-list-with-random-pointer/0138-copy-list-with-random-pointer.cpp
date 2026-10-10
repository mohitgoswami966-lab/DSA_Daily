/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp=head;
        while(temp){
            Node* copy= new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }
        temp=head;
        while(temp){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* copyHead=head->next;
        Node* copyTail=copyHead;
        while(temp){
            Node* copy=temp->next;
            temp->next=copy->next;
            temp=temp->next;
            if(temp){
                copyTail->next=temp->next;
                copyTail=copyTail->next;
            }
        }
        return copyHead;
    }
};