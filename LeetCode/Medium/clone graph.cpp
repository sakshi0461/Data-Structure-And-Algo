/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* root=NULL;
       if(node==NULL) return root;
        
        root=new Node(node->val);
        
        queue<Node*>q;
        q.push(node);
        
        unordered_map<Node*,Node*>visited;
        visited[node]=root;
        
        while(!q.empty()){
            int i=q.size();
           
            while(i--){
            Node* p=visited[q.front()];
                for(int j=0;j<(q.front()->neighbors).size();j++){
                   Node* l=NULL;
                   Node* n=(q.front()->neighbors)[j];
                 
                  if(visited.find(n)!=visited.end())
                    l=visited[n];
                  else{
                    l=new Node(n->val);
                        q.push(n);
                        visited[n]=l;
                  }
                    (p->neighbors).push_back(l);
                
                }
                
                q.pop();
            }
        }
        return root;
    }
};