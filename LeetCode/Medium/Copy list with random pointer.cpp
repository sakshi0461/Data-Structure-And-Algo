/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node*,Node*>mp;
        Node* root=NULL;
        if(head==NULL) return root;
        Node* node=head;
        Node* p=NULL;
        while(node!=NULL){
          Node* k=NULL;
            
            if(mp.find(node)==mp.end()){
              k=new Node(node->val); 
              mp[node]=k;
            }
            else
                k=mp[node];
            
            if(node->random==NULL)
                   k->random=NULL;
            else{
                if(mp.find(node->random)!=mp.end())
                    k->random=mp[node->random];
                 else{
                    k->random=new Node(node->random->val);
                    mp[node->random]=k->random;
                  }        
                }
            
            if(root==NULL)
                root=k;            
            else
                p->next=k;
            p=k;
            
            node=node->next;
        }
        
        return root;
    }
};