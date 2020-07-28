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
    int s=0;
    int endlevel(TreeNode* root){
        if(root==NULL)
            return 0;
        return 1+max(endlevel(root->right),endlevel(root->left));
    }
    int sum(TreeNode* root,int lev,int i){
        if(root==NULL) return 0;
        if(i==lev)
            s+=root->val;
        sum(root->right,lev+1,i);
        sum(root->left,lev+1,i);
        return s;
    }
    int deepestLeavesSum(TreeNode* root) {
        int lev=endlevel(root);
        return sum(root,1,lev);
    }
};