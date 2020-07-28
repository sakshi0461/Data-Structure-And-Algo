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
    ListNode* reverseList(ListNode* head) {
        // if(head==NULL || head->next==NULL) return head;
        // ListNode* reverse=reverseList(head->next);
        // head->next->next=head;
        // head->next=NULL;
        // return reverse;
            ListNode* curr=head,*agla,*pre=NULL;
        
        while(curr){
            agla=curr->next;
            curr->next=pre;
            pre=curr;
            curr=agla;
        }
        return pre;
    }
};