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
    void find(TreeNode* root,vector<string>&v,string s){
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL){
            v.push_back(s+(to_string(root->val)));
            return;
        }
        
        find(root->left,v,s+(to_string(root->val))+"->");
        find(root->right,v,s+(to_string(root->val))+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        find(root,v,"");
        
        return v;
    }
};