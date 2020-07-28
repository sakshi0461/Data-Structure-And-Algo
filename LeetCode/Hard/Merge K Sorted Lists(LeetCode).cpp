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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* res=NULL;
        
        if(l1->val>l2->val){
            res=l2;
            res->next=merge(l1,l2->next);
        }
        else{
            res=l1;
            res->next=merge(l1->next,l2);
        }
        
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.size()==0)
          return NULL;
        
        ListNode* res=NULL;
        
        for(int i=0;i<lists.size();i++)
            res=merge(res,lists[i]);
        
        return res;
    }
};