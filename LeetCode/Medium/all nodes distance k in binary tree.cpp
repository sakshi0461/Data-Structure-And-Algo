/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void below(TreeNode* root,int depth,int d,vector<int>&v){
       
        if(root==NULL) return;
        
        if(d==depth){
            v.push_back(root->val);
            return;
        }
        
        below(root->left,depth,d+1,v);
        below(root->right,depth,d+1,v);
    }
    bool isintree(TreeNode* root,TreeNode* target){
        
        if(root==NULL) return false;
        
        if(root==target) return true;
        
        return isintree(root->left,target) | isintree(root->right,target);
    }
    void storeparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp,TreeNode* p){
        if(root==NULL) return;
        
        mp[root]=p;
        
        storeparent(root->left,mp,root);
        storeparent(root->right,mp,root);
        
    }
    void DFS(TreeNode* node,int depth,int d,vector<int>&v){
        
        if(node==NULL) return;
        
        if(depth<d) return;
        
        if(depth==d){
            v.push_back(node->val);
            return;
        }
        
        DFS(node->left,depth,d+1,v);
        DFS(node->right,depth,d+1,v);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        unordered_map<TreeNode*,TreeNode*>mp;
        storeparent(root,mp,NULL);
        
        vector<int>v;
        
        below(target,K,0,v);
        
        TreeNode* i=mp[target];
        int j=1;
        
        while(i!=NULL){
            bool left=isintree(i->left,target);
            if(K-j==0)
                v.push_back(i->val);
            else{
            if(left)
                DFS(i->right,K-j,1,v);
            else
                DFS(i->left,K-j,1,v);
            }
            i=mp[i];
            j++;
        }
        
        return v;
    }
};