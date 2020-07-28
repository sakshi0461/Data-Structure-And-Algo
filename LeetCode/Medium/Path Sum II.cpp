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
    void path(TreeNode* root,int sum,vector<vector<int>>&v,vector<int>temp){
        if(root==NULL) return;
        
        if(!root->left && !root->right){
            if(sum==root->val){
                temp.push_back(root->val);
                v.push_back(temp);
            }
            return;
        }
        
        temp.push_back(root->val);
        path(root->left,sum-root->val,v,temp);
        path(root->right,sum-root->val,v,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>temp;
        vector<vector<int>>v;
        path(root,sum,v,temp);
        return v;
    }
};