/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "*";
        
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    int pos=0;
    // Decodes your encoded data to tree.
    int helper(string data){
        long long int num=0;
        string s="";
        while(data[pos]!=',' && !(data[pos]>='a' && data[pos]<='z')){
           s+=data[pos];
            pos++;
        }
        if(data[pos]==',')
            pos++;
        num=stoi(s);
        return num;
    }
    TreeNode* deserialize(string data) {
        if(data[pos]=='*'){
            pos+=2;
            return NULL;
        }
        TreeNode* root=new TreeNode(helper(data));
        root->left=deserialize(data);
        root->right=deserialize(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));