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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>inorder;
        
        stack<TreeNode*>s;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
           TreeNode* curr=s.top();
            inorder.push_back(curr->val);
            s.pop();
            root=curr->right;
            if(root==NULL && s.empty()) break;
        }
        
        return inorder;
    }
};