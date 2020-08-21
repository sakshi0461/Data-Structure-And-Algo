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
    void inorder(TreeNode* root,stack<int>&s){
        if(root==NULL)
            return;
        
        inorder(root->right,s);
        s.push(root->val);
        inorder(root->left,s);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      
        vector<int>sorted;
        
        stack<int>s1;
        stack<int>s2;
        inorder(root1,s1);
        inorder(root2,s2);
        
        while(!s1.empty() && !s2.empty()){
            if(s1.top()>s2.top()){
                sorted.push_back(s2.top());
                s2.pop();
            }
            else{
                sorted.push_back(s1.top());
                s1.pop();
            }
        }
        
        while(!s1.empty()){
            sorted.push_back(s1.top());
            s1.pop();
        }
        
        while(!s2.empty()){
            sorted.push_back(s2.top());
            s2.pop();
        }
        
        return sorted;
    }
};