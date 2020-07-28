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
     int height(TreeNode* root){
         if(root==NULL) return 0;
         
         return 1+max(height(root->left),height(root->right));
     }
     int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL) return 0;
         
         int lh=height(root->left);
         int rh=height(root->right);
         
         int ld=diameterOfBinaryTree(root->left);
         int rd=diameterOfBinaryTree(root->right);
         
         return max({lh+rh,ld,rd});
     }
//     //METHOD 2
//     int maxi;
//     int dia(TreeNode* root){
//         if(root==NULL) return 0;
        
//         int l=dia(root->left);
//         int r=dia(root->right);
        
//         maxi=max(maxi,l+1+r);
        
//         return max(l,r)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//          maxi=0;
//         if(root==NULL) return 0;
//         dia(root);
//         return maxi-1;
//     }
};