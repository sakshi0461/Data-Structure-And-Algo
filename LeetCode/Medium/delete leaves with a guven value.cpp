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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL)
            return NULL;
        
       if(!root->left && !root->right){
           if(root->val==target)
               return NULL;
           else
               return root;
       }
        
       TreeNode* left=removeLeafNodes(root->left,target);
       TreeNode* right=removeLeafNodes(root->right,target);
        
       root->left=left;
       root->right=right;
        
        if(!left && !right && root->val==target)
            return NULL;
        
        return root;
    }
};