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
    TreeNode* buildtree(vector<int>&nums,int start,int end){
        if(start>end)
            return NULL;
        
        int index,maxi=INT_MIN;
        
        for(int i=start;i<=end;i++)
            if(nums[i]>maxi){
                maxi=nums[i];
                index=i;
            }
        
        TreeNode* node=new TreeNode(nums[index]);
        
        node->left=buildtree(nums,start,index-1);
        node->right=buildtree(nums,index+1,end);
        
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
      return buildtree(nums,0,nums.size()-1);
    }
};