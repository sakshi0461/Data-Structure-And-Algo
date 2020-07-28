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
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* construct(vector<int>&v,int start,int end){
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* node=new TreeNode(v[mid]);
        
        node->right=construct(v,mid+1,end);
        node->left=construct(v,start,mid-1);
        
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
    return  construct(v,0,v.size()-1);

    }
};S