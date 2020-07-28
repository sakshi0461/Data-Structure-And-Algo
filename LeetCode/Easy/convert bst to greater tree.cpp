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
    void convert(TreeNode* root,int &val){
        if(root==NULL) return;
        
        convert(root->right,val);
        val+=root->val;
        root->val=val;
        convert(root->left,val);
    }
    TreeNode* convertBST(TreeNode* root) {
      int v=0;
      convert(root,v);  
      return root;
    }
};