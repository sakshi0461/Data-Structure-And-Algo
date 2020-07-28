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
        ListNode* fast=headA,*f2=headB;
        
        bool i=true;
        bool j=true;
        while(fast && f2){
            if(fast==f2) return fast;
            fast=fast->next;
            f2=f2->next;
            if(!fast && i){
                fast=headB;
                i=false;
            }
            if(!f2 && j){
                f2=headA;
                j=false;
            }
        }
        
        return NULL;
    }
};