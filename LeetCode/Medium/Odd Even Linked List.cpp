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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* last=head,*curr=head,*check,*pre=NULL;
        int n=0;
        while(last->next){
            last=last->next;
            n++;
        }
        check=last;
        bool i=true;
        int j=0;
        
        while(j<=n){
            if(j%2!=0){
                if(curr==head)
                    head=head->next;
                else
                    pre->next=curr->next;
                last->next=curr;
                curr=curr->next;
                last=last->next;
                last->next=NULL;
                j++;
                continue;
            }
            j++;
            pre=curr;
            curr=curr->next;
        }
        
        return head;
    }
};