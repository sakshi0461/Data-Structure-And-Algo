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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        int carry=0;
        ListNode* root=NULL,*p=NULL;
        while(l1!=NULL || l2!=NULL){
           int a,b;
            if(l1==NULL)
              a=0;
            else{
              a=l1->val;
              l1=l1->next;
            }
            if(l2==NULL)
              b=0;
            else{
              b=l2->val;
              l2=l2->next;
             }
            ListNode* node=new ListNode((a+b+carry)%10);
            if(root==NULL)
                root=node;
            else
                p->next=node;
            p=node;
            carry=((a+b+carry)-node->val)/10;
        }
        if(carry!=0){
            ListNode* node=new ListNode(carry);
            p->next=node;
        }
        return root;
    }
};