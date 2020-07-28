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
    int maxi;
    int longest(TreeNode* root){
        
        if(root==NULL) return 0;
        
        int a=0,b=0;
        int t1=longest(root->left);
        int t2=longest(root->right);
        if(root->left){
            if(root->val==root->left->val)
                a=1+t1;
        }
        if(root->right){
            if(root->val==root->right->val)
                b=1+t2;
        }
         maxi=max(maxi,a+b);
        return max(a,b);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        maxi=0;
        longest(root);
        return maxi;
    }
};