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
    vector<TreeNode*> generate(int start,int end){
        vector<TreeNode*>v;
        
        if(start>end){
            v.push_back(NULL);
            return v;
        }
    
        for(int i=start;i<=end;i++){
          vector<TreeNode*>leftarr=generate(start,i-1);
          vector<TreeNode*>rightarr=generate(i+1,end);
            
            for(int l=0;l<leftarr.size();l++){
                for(int r=0;r<rightarr.size();r++){
                    TreeNode* node=new TreeNode(i);
                    node->left=leftarr[l];
                    node->right=rightarr[r];
                    v.push_back(node);
                }
            }
        }
        
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>v;
        if(n==0) return v;
        v=generate(1,n);
        return v;
    }
};