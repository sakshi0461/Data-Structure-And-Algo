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
    bool iscontain(TreeNode* root){
        if(root==NULL)
            return false;
        
        if(root->val==1) 
            return true;
        
        return iscontain(root->left) || iscontain(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root==NULL)
            return NULL;

        if(root->val==0){
            bool contain=iscontain(root);
            if(!contain)
               return NULL;                
        }
        
           root->left=pruneTree(root->left);
           root->right=pruneTree(root->right);
        
        return root;
    }
};