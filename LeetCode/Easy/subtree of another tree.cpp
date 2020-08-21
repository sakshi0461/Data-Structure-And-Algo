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
    bool issame(TreeNode* root,TreeNode* node){
        if(!root && !node) return true;
        if(!root || !node) return false;
        
        if(root->val==node->val)
            return issame(root->left,node->left) && issame(root->right,node->right);
        
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(!s && !t) return true;
        if(!s && t) return false;
        if(s && !t) return false;
        
        if(s->val==t->val)
            if(issame(s->left,t->left) && issame(s->right,t->right))
                return true;
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};