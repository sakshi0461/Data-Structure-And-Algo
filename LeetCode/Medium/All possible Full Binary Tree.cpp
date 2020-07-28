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
    vector<TreeNode*> create(int n){
        if(n==0) return {};
        TreeNode* t=new TreeNode(0);
        if(n==1) return {t};
        
        vector<TreeNode*>res;
        
        for(int i=1;i<n-1;i++){
            vector<TreeNode*>left=create(i);
            vector<TreeNode*>right=create(n-1-i);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(0);
                    root->left=left[j];
                    root->right=right[k];
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        return create(N);
    }
};