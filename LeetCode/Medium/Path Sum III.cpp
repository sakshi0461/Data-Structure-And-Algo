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
    int path(TreeNode* root,int sum){
        if(root==NULL) return 0;

        int count=0;
        if(sum==root->val)
            count++;
        
        return count+=path(root->left,sum-root->val) + path(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL) return 0;
        
        int count=0;
        
        count=path(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);

        return count;
    }
};