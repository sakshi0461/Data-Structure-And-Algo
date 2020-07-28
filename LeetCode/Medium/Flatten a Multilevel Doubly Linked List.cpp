/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* root=head;
        while(head){
            if(head->child){
                Node* curr=head->child;
                head->child->prev=head;
               
                while(curr->next)
                    curr=curr->next;
                
                curr->next=head->next;
                
                if(head->next)
                head->next->prev=curr;
                
                head->next=head->child;
                head->child=NULL;
            }
            head=head->next;
        }
        return root;
    }
};