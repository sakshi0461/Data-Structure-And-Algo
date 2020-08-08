/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
     bool count(TreeNode* root,int val){
         
         if(root==NULL) return false;
         
         if(root->left==NULL && root->right==NULL){
             if(root->val==val) return true;
             return false;
         }
         
         if(root->left && root->right){
             if(root->left->val==val && root->right->val==val)
             return count(root->left,val) && count(root->right,val);
              return false;
         }
         if(root->left){
             if(root->left->val==val) 
               return count(root->left,val);
             return false;
         }
         if(root->right){
             if(root->right->val==val) 
             return count(root->right,val);
              return false;
         }
         
         return true;
     }
    int countUnivalSubtrees(TreeNode * root) {
       
       if(root==NULL)
         return 0;
         
         int p=0;
         
         if(count(root,root->val))
           p=1;
           
     return p+countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right); 
    }
};