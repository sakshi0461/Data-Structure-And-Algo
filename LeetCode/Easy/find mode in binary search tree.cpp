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
    void inorder(TreeNode* root,unordered_map<int,int>&mp,int &maxi){
        if(root==NULL) return;
        
        inorder(root->left,mp,maxi);
        mp[root->val]++;
        if(maxi<mp[root->val])
            maxi=mp[root->val];
        inorder(root->right,mp,maxi);
    }
    vector<int> findMode(TreeNode* root) {
        
        vector<int>mode;
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        inorder(root,mp,maxi);
        
        for(auto i:mp)
            if(i.second==maxi)
                mode.push_back(i.first);
        
        return mode;
    }
};