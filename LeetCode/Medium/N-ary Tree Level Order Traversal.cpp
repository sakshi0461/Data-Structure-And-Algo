/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>>v;
        if(root==NULL) return v;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int i=q.size();
            vector<int>tmp;
            while(i--){
                tmp.push_back(q.front()->val);
                for(int i=0;i<(q.front()->children).size();i++){
                    if((q.front()->children)[i])
                       q.push((q.front()->children)[i]);
                }
                q.pop();
            }
            v.push_back(tmp);
        }
        return v;
    }
};