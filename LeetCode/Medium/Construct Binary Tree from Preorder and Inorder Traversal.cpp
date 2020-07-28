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
    TreeNode* create(vector<int>&preorder,vector<int>&inorder,int &index,int start,int end,unordered_map<int,int>&mp){
        if(start>=end+1) return NULL;
        
        TreeNode* node=new TreeNode(preorder[index]);
         int indexininorder=mp[preorder[index]];
        index++;
        if(start==end) return node;
        
        node->left=create(preorder,inorder,index,start,indexininorder-1,mp);
        node->right=create(preorder,inorder,index,indexininorder+1,end,mp);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //PREORDER DLR
        //INORDER LDR
        int i=0;
        unordered_map<int,int>mp;
        for(int j=0;j<inorder.size();j++)
            mp[inorder[j]]=j;
     
        return create(preorder,inorder,i,0,inorder.size()-1,mp);
    }
};