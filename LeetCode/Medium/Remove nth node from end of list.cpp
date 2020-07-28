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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) return head;
        
        ListNode* m=head,*mn=head,*pre=NULL;
        
        while(n--)
            mn=mn->next;
        
        if(!mn)
            return head->next;
        
        while(mn){
            pre=m;
            m=m->next;
            mn=mn->next;
        }
        
        pre->next=m->next;
        m->next=NULL;
        
        return head;
    }
};