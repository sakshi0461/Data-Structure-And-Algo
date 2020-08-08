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
    bool find(TreeNode* root,TreeNode* node){
        
        if(root==NULL) return false;
        
        if(node==root) return true;
        
        return find(root->right,node) | find(root->left,node);
    }
    TreeNode* LCA(TreeNode* root1,TreeNode* root2,TreeNode* root){
        
        if(root1==root || root2==root) return root;
        
        bool left1=find(root->left,root1);
        bool left2=find(root->left,root2);
        bool right1=find(root->right,root1);
        bool right2=find(root->right,root2);
        
        if(left1 && left2)
            return LCA(root1,root2,root->left);
        if(right1 && right2)
            return LCA(root1,root2,root->right);
        return root;
    }
    int maxdepth(TreeNode* root){
        if(root==NULL) return 0;
        
        return 1+max(maxdepth(root->left),maxdepth(root->right));
    }
    void funct(TreeNode* root,int depth,int maxi,vector<TreeNode*>&v){
        
        if(depth==maxi){
            v.push_back(root);
            return;
        }
        
        if(root->left)
            funct(root->left,depth+1,maxi,v);
        if(root->right)
            funct(root->right,depth+1,maxi,v);
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        int maxi=maxdepth(root);
        
        vector<TreeNode*>v;
        funct(root,1,maxi,v);
        
        TreeNode* res=v[0];
        
        for(int i=1;i<v.size();i++)
            res=LCA(res,v[i],root);
        
        return res;
    }
};