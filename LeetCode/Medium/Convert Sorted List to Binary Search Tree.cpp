/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(vector<int>&v,int start,int end){
        if(start>end) return NULL;
        
        int mid=start+(end-start)/2;
        
        TreeNode* node=new TreeNode(v[mid]);
        
        if(start==end) return node;
        
        node->left=build(v,start,mid-1);
        node->right=build(v,mid+1,end);
        
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head=head->next;
        }
        return build(nums,0,nums.size()-1);   
    }
};