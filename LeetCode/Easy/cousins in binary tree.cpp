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
    int level(TreeNode* root,int data,int lev,TreeNode* &parent){
      if(root==NULL) return 0;
      
        if(root->val==data) return lev;
        
        parent=root;
        int d=level(root->left,data,lev+1,parent);
        
        if(d!=0)
            return d;
        parent=root;
        return level(root->right,data,lev+1,parent);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        if(root->val==x||root->val==y) return false;

        TreeNode* xp=NULL,*yp=NULL;
        int a=level(root,x,0,xp),b=level(root,y,0,yp);
        
        if(a==b && xp!=yp)
            return true;
       // cout<<xp->val<<" "<<yp->val<<" ";
        return false;
    }
};