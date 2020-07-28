/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* A) {
        if(A==NULL) return A;
         Node* curr=A,*temp,*p,*l=A;
         curr->next=NULL;
    while(curr->left || curr->right){
         temp=curr;
         p=NULL;
        while(temp){
            if(p){
                if(p->right){
                    if(temp->left)
                      p->right->next=temp->left;
                    else if(temp->right)
                      p->right->next=temp->right;
                }
                else if(p->left){
                    if(temp->left)
                      p->left->next=temp->left;
                    else if(temp->right)
                      p->left->next=temp->right;
                }
            }
            if(temp->left)
              temp->left->next=temp->right;
            if(temp->right)
            temp->right->next=NULL;
            if(temp->right || temp->left)
              p=temp;
           temp=temp->next; 
        }
        if(curr->left==NULL && curr->right==NULL){
            while(curr->left==NULL && curr->right==NULL){
                curr=curr->next;
            }
        }
        if(curr->left!=NULL)
          curr=curr->left;
        else if(curr->right!=NULL)
          curr=curr->right;
         }
      return l;
    }
};