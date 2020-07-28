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
    void modify(TreeNode* &root,int &sum){
        if(root==NULL) return;
        modify(root->right,sum);
        sum+=root->val;
        root->val=sum;
        modify(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        modify(root,sum);
        return root;
    }
};