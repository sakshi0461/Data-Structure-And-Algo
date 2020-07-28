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
    
    int widthOfBinaryTree(TreeNode* root) {
     
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push(make_pair(root,1));
        unsigned long long int maxi=0;
            while(!q.empty()){
                    int si=q.size();
                    unsigned long long int l=0,r=0;
                    l=q.front().second;
                    while(si--){
                            if(si==0)
                               r=q.front().second;
                            pair<TreeNode*,unsigned long long int>p=q.front();
                            q.pop();
                            if(p.first->left)
                                 q.push(make_pair(p.first->left,p.second*2));
                            if(p.first->right)
                                 q.push(make_pair(p.first->right,(p.second*2)+1));
                    }
                    maxi=max(maxi,r-l+1);
            }
            
            return maxi;
    }
};