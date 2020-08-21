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
    int index;
    TreeNode* buildtree(unordered_map<int,int>inorder,vector<int>preorder,int start,int end){
    
        if(start>end)
            return NULL;
        
        int val=preorder[index];
        index++;
        
        TreeNode* node=new TreeNode(val);
        
        if(start==end)
            return node;
        
        int mid=inorder[val];
        
        node->left=buildtree(inorder,preorder,start,mid-1);
        node->right=buildtree(inorder,preorder,mid+1,end);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int>in=preorder;
        sort(in.begin(),in.end());
        
        unordered_map<int,int>inorder;
        
        for(int i=0;i<preorder.size();i++)
            inorder[in[i]]=i;
        
        index=0;
        
       return buildtree(inorder,preorder,0,preorder.size()-1);
    }
};