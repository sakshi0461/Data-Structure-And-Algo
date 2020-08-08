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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL && root2!=NULL) return false;
        if(root1!=NULL && root2==NULL) return false;
        
        bool b1,b2,b3,b4;
        
        if(root1->val==root2->val){
           b1=flipEquiv(root1->left,root2->right);
           b2=flipEquiv(root1->left,root2->left);
           b3=flipEquiv(root1->right,root2->left);
           b4=flipEquiv(root1->right,root2->right);
        }
        else
          return false; 
        
        if(b1 && b3) return true;
        
        if(b2 && b4) return true;
        
        return false;
    }
};