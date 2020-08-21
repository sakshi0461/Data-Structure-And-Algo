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
class FindElements {
public:
    TreeNode* tree;
    TreeNode* recover(TreeNode* root,int val){
        if(root==NULL)
            return NULL;
        
        TreeNode* node=new TreeNode(val);
        
        node->left=recover(root->left,2*val+1);
        node->right=recover(root->right,2*val+2);
        
        return node;
    }
    FindElements(TreeNode* root) {
        tree=recover(root,0);
    }
    
    bool findElement(TreeNode* node,int target){
        if(node==NULL)
            return false;
        
        if(node->val==target)
            return true;
        
        return findElement(node->left,target) || findElement(node->right,target);
    }
    bool find(int target) {
        TreeNode* root=tree;
        return findElement(root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */