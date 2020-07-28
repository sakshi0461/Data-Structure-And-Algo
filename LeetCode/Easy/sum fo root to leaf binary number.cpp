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
    int sum=0;
    void sumrl(TreeNode* root,int temp){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            temp=(temp<<1)+root->val;
            sum+=temp;
        }
        sumrl(root->left,(temp<<1)+root->val);
        sumrl(root->right,(temp<<1)+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        int temp=0;
        sumrl(root,temp);
        return sum;
    }
};