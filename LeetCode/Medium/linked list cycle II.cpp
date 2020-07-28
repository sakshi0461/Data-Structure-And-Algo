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
  //THIS IS HASHING BASED WHEN A OLD ELEMENT COMES AGAIN THEN IT WILL BE THE STARTING POINT
    // ListNode *detectCycle(ListNode *head) {
    //  unordered_set<ListNode*>mp;
    //    ListNode* node=head;
    //    while(node!=NULL){
    //      if(mp.find(node)==mp.end())
    //        mp.insert(node);
    //      else
    //        return node;
    //      node=node->next;
    //    }
    //   return NULL;
    // }
  //This METHOD IS BASED ON EQUATING TIME
     ListNode *detectCycle(ListNode *head) {
     if(head==NULL || head->next==NULL)
       return NULL;
      ListNode* slow=head,*fast=head;
       while(fast!=NULL && fast->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
         if(fast==slow)
           break;
       }
       if(slow!=fast)
         return NULL;
       slow=head;
       while(slow!=fast){
         slow=slow->next;
         fast=fast->next;
       }
       return slow;
    }
  //THIS METHOD MODIFY THE LINKED LIST BY MAKING NEXT OF EACH POINTER NULL
//       ListNode *detectCycle(ListNode *head) {
//         ListNode* temp=NULL,*agla=head;
        
//         while(agla!=NULL){
//           if(agla->next==temp)
//             return agla;
//           ListNode* t=agla->next;
//           agla->next=temp;
//           agla=t;
//         }
//         return NULL;
//       }
};