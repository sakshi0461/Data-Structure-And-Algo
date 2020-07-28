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
    int finalmaxi=INT_MIN;
    int helper( TreeNode* node) {
        if(node==NULL) return 0;
        
        int left = 0, right = 0;
        
        if(node->left)  
            left = helper(node->left);
        
        if(node->right) 
            right = helper(node->right);
        
        int leftOrRightOrNode = max(node->val,node->val+max(left,right));
        
        finalmaxi= max(finalmaxi,max(node->val+left+right,leftOrRightOrNode));        
        return leftOrRightOrNode;
    }
    int maxPathSum(TreeNode* root) {
/*first for the root node include it and the find maximum in root->left including root->left and the maximum in root->right including root->right and the move to root->left then do same thing for root->left and the move to root->right and do same thing to root->right and then find maximum in root-,root->left,root->right*/
        helper(root);
        return finalmaxi;
     //return finalmaxi;   
  }
};