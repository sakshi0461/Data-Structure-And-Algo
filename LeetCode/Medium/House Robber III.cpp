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
    //METHOD 2
    int robb(TreeNode* root,int &l,int &r){
        if(root==NULL) return 0;
        
        int ll=0,lr=0,rr=0,rl=0;
        l=robb(root->left,ll,lr);
        r=robb(root->right,rl,rr);
        
        return max(root->val+ll+lr+rr+rl,l+r);
    }
    int rob(TreeNode* root){
        int l,r;
        return robb(root,l,r);
    }
    //METHOD 1
//     int robb(TreeNode* root,unordered_map<TreeNode*,int>dp){
//          if(dp.find(root)!=dp.end()) return dp[root];
//         if(root==NULL) return dp[root]=0;
        
//         if(root->right==NULL && root->left==NULL) return dp[root]=root->val;
      
//         int a=0,b=0,q=0,r=0,s=0,t=0;
        
//         //CASE 1- INCLUDE ROOT
//         //CASE 2- EXCLUDE ROOT
//         if(root->right){
//             if(root->right->left)
//                 q=robb(root->right->left,dp);
//             if(root->right->right)
//                 r=robb(root->right->right,dp);
//         }
//         if(root->left){
//             if(root->left->left)
//                 s=robb(root->left->left,dp);
//             if(root->left->right)
//                 t=robb(root->left->right,dp);
//         }
//         a=root->val+q+r+s+t;
//         b=robb(root->left,dp)+robb(root->right,dp);
//         return dp[root]=max(a,b);
//     }
//     int rob(TreeNode* root) {
//         unordered_map<TreeNode*,int>dp;
//         return robb(root,dp);
//     }
};