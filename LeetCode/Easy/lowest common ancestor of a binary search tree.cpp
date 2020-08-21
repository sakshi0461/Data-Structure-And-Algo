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
    bool find(TreeNode* root,TreeNode* node){
        if(root==NULL) return false;
        
        if(root==node) return true;
        
        return find(root->right,node) | find(root->left,node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
            return NULL;
        
        if(root==p || root==q) return root;
        
        bool isinleft1=find(root->left,p);
        bool isinleft2=find(root->left,q);
        bool isinright1=find(root->right,p);
        bool isinright2=find(root->right,q);
        
        if(isinleft1 && isinleft2)
            return lowestCommonAncestor(root->left,p,q);
        if(isinleft1 && isinright2)
            return root;
        if(isinright1 && isinleft2)
            return root;
        return lowestCommonAncestor(root->right,p,q);
    }
};