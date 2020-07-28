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
    void findinorder(TreeNode* root,vector<int>&leaf){
        if(root==NULL) return;
        
        findinorder(root->left,leaf);
        leaf.push_back(root->val);
        findinorder(root->right,leaf);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>leaf;
        findinorder(root,leaf);
        TreeNode* node=NULL,*p=NULL;
        for(int i=0;i<leaf.size();i++){
            TreeNode* temp=new TreeNode(leaf[i]);
            if(node==NULL)
                node=temp;
            else
                p->right=temp;
            p=temp;
        }
        
        return node;
    }
};