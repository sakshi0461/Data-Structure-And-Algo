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
//     void flatten(TreeNode* root) {
//         while(root){
           
//             TreeNode* curr=root->left;
            
//             if(curr==NULL){
//                 root=root->right;
//                 continue;
//             }
            
//             while(curr && curr->right)
//                 curr=curr->right;
            
//             curr->right=root->right;
//             root->right=root->left;
//             root->left=NULL;
//             root=root->right;
//         }
//     }
    void f(TreeNode* &root){
        TreeNode* head=root;
        while(head->left)
            head=head->left;
        TreeNode* l=head;
        head=root;
        root=l;
           while(head){
            
                TreeNode* curr=head->left;
            if(curr==NULL){
                head=head->right;
                continue;
            }
            
            while(curr && curr->right)
                curr=curr->right;
            
            curr->right=head;
            TreeNode* l=head;
            head=head->left;
            l->left=NULL;
        }
    }
    void flatten(TreeNode* root){
        f(root);
        while(root){
            cout<<root->val<<" ";
            if(!root->left)
                cout<<"yes ";
            root=root->right;
        }
    }
};