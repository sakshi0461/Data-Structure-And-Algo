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
class BSTIterator {
public:
//CONVERT BINARY TREE IN INORDER MORRIS TRAVERSAL 
//     TreeNode* small;
//     TreeNode* f(TreeNode* root){
//         TreeNode* head=root;
//         while(head->left)
//             head=head->left;
        
//            while(root){
            
//                 TreeNode* curr=root->left;
//             if(curr==NULL){
//                 root=root->right;
//                 continue;
//             }
            
//             while(curr && curr->right)
//                 curr=curr->right;
            
//             curr->right=root;
//             TreeNode* l=root;
//             root=root->left;
//             l->left=NULL;
//         }
//         return head;
//     }
    vector<int>v;
    int i;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        v.clear();
        i=0;
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return v[i++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return i<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */