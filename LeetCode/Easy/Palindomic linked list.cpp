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
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return true;
        
        ListNode* m=head,*mn=head;
        
        while(mn->next && mn->next->next){
            m=m->next;
            mn=mn->next->next;
        }
        
        ListNode* curr=m->next,*agla,*pre=NULL;
        m->next=NULL;
        
        while(curr){
          agla=curr->next;
          curr->next=pre;
          pre=curr;
          curr=agla;
        }
        
        ListNode* temp=head;
        
        while(temp && pre){
            if(temp->val!=pre->val)
                return false;
            temp=temp->next;
            pre=pre->next;
        }
        
        return true;
    }
};