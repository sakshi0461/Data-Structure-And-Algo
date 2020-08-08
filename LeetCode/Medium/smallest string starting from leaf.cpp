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
    string mini;
    void findmini(TreeNode* root,string s){
        
        if(root==NULL)
            return;
        
        char d='a'+root->val;
        
        if(root->left==NULL && root->right==NULL){
            s=s+d;
            reverse(s.begin(),s.end());
            if(mini=="")
                mini=s;
            else
                mini=min(mini,s);
            return;
        }
        
        findmini(root->left,s+d);
        findmini(root->right,s+d);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        
        mini="";
        findmini(root,"");
        return mini;
    }
};