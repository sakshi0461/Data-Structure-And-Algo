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
    bool find(TreeNode* root,int val){
        if(root==NULL) return true;
        if(root->val==val)
            return find(root->left,val) & find(root->right,val);
        return false;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return false;
        int val=root->val;
        return find(root,val);
    }
};