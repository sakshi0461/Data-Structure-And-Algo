/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isintree(TreeNode* root,TreeNode* p){
        if(root==NULL) return false;
        if(root==p) return true;
        
        return isintree(root->left,p) | isintree(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        bool pleft=isintree(root->left,p) | (root==p);
        bool pright=isintree(root->right,p) | (root==p);
        bool qleft=isintree(root->left,q) | (root==q);
        bool qright=isintree(root->right,q) | (root==q);
        
        if((pleft & qright) | (pright & qleft))
            return root;
        else if(pleft & qleft) 
            return lowestCommonAncestor(root->left,p,q);
        
        return lowestCommonAncestor(root->right,p,q);
    }
};