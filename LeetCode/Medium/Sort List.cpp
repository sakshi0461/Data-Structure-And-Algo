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
    ListNode* mergeList(ListNode* first,ListNode* second){
        if(!first) return second;
        if(!second) return first;
        
        ListNode* res;
        
        if(first->val>=second->val){
            res=second;
            res->next=mergeList(first,second->next);
        }
        else{
            res=first;
            res->next=mergeList(first->next,second);
        }
        
        return res;
    }
    void splitlist(ListNode* &head,ListNode* &first,ListNode* &second){
        ListNode* fast=head,*slow=head;
        
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        second=slow->next;
        slow->next=NULL;
        first=head;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* first=NULL,*second=NULL;
        
        splitlist(head,first,second);
        
        first=sortList(first);
        second=sortList(second);
        
        return mergeList(first,second);
    }
};