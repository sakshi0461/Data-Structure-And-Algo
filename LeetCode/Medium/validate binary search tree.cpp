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
    bool isvalid(int mini,int maxi,TreeNode* root){
        if(root==NULL) return true;
        
            if(root->val==maxi && maxi==INT_MAX){
                if(root->right) return false;
                return isvalid(mini,root->val-1,root->left);
            }
            if(root->val==mini && mini==INT_MIN){
                if(root->left) return false;
                return isvalid(root->val+1,maxi,root->right);
            }
          if(root->val>=mini && root->val<=maxi)
            return isvalid(mini,root->val-1,root->left) & isvalid(root->val+1,maxi,root->right);
         return false;
    }
    bool isValidBST(TreeNode* root) {
     int maxi=INT_MAX,mini=INT_MIN;
        if(isvalid(mini,maxi,root))
            return true;
        return false;
    }
};