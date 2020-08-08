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
    void funct(TreeNode* root,int dist,unordered_map<int,vector<TreeNode*>>&mp){
        
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL)
          mp[dist].push_back(root);
        
        funct(root->left,dist+1,mp);
        funct(root->right,dist+1,mp);
        
        return;
    }
    int countPairs(TreeNode* root, int distance) {
        
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        
        unordered_map<int,vector<TreeNode*>>ll;
        unordered_map<int,vector<TreeNode*>>rr;
        
        funct(root->left,1,ll);
        funct(root->right,1,rr);
        
        int count=0;
        
        for(int i=distance;i>0;i--){
            for(int j=1;j<i;j++){
                 count+=(ll[j].size())*(rr[i-j].size());
            }
        }
    
        return count+countPairs(root->left,distance)+countPairs(root->right,distance);
    }
};