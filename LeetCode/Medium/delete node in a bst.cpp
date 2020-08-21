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
    int findmaxi(TreeNode* root){
        if(root==NULL)
            return 0;
        
        if(!root->right)
            return root->val;
        
        return findmaxi(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val>key){ 
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        
        
        if(!root->left && !root->right)
            return NULL;
        else if(root->left && !root->right)
            return root->left;
        else if(root->right && !root->left)
            return root->right;
        
        root->val=findmaxi(root->left);
        root->left=deleteNode(root->left,root->val);
        
        return root;
    }
};