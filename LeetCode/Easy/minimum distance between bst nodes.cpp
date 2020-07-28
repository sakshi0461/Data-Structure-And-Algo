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
    //METHOD 1
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int mini=INT_MAX;
        for(int i=1;i<v.size();i++)
            if(mini>v[i]-v[i-1])
                mini=v[i]-v[i-1];
        return mini;
    }
    //METHOD 2
    int mini=INT_MAX,pre=-1;
    int minDiffInBST(TreeNode* root){
        if(root->left)
            minDiffInBST(root->left);
        if(pre>-1)
            mini=min(mini,root->val-pre);
        pre=root->val;
        if(root->right)
            minDiffInBST(root->right);
        return mini;
    }
};