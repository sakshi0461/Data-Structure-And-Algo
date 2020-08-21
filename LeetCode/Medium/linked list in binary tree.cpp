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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool havepath(ListNode* head,TreeNode* root){
        if(!root && head) return false;
        if(!head) return true;
        
        if(root->val==head->val)
            return havepath(head->next,root->left) || havepath(head->next,root->right);
        
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(!root && !head) return true;
        if(root && !head) return true;
        if(!root && head) return false;
        
        bool res=false;
        
        if(root->val==head->val)
          res=havepath(head,root);
            
        return res || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};