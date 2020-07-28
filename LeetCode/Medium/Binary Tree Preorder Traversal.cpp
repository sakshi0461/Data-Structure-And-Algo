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
  // METHOD 1
    void preorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(root,v);
        return v;
    }
 // METHOD 2-USING STACK
     vector<int> preorderTraversal(TreeNode* root) {
       vector<int>v;
         if(root==NULL) 
            return v;
       stack<TreeNode*>s;
       s.push(root);
         while(!s.empty()){
             int i=s.size();
             while(i--){
                 v.push_back(s.top()->val);
                TreeNode* curr=s.top();
                 s.pop();
                 if(curr->right)
                    s.push(curr->right);
                 if(curr->left)
                   s.push(curr->left);
             }
         }
        return v;
    }
  //METHOD 3-MORRIS TRAVERSAL
    vector<int> preorderTraversal(TreeNode* root) {
      TreeNode* curr=root;
      vector<int>v;
        if(curr==NULL) return v;
        while(curr!=NULL){
            if(curr->left==NULL){
                v.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* head=curr->left;
                while(head->right)
                    head=head->right;
                head->right=curr;
                head=curr;
                curr=curr->left;
                head->left=NULL;
            }
        }
        return v;
    }
};