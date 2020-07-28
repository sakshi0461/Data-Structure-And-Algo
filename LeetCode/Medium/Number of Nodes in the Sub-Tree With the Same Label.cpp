class Solution {
public:
    vector<int> DFS(int src,unordered_map<int,vector<int>>&graph,string label,vector<int>&parent,vector<vector<int>>&v){
                
            for(auto j:graph[src]){
                if(j==parent[src]) continue;
                 vector<int>count=DFS(j,graph,label,parent,v);       
                 for(int i=0;i<26;i++)
                     v[src][i]+=count[i];
            }
        
        v[src][label[src]-'a']++;
        
        return v[src];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        unordered_map<int,vector<int>>graph;
        
        bool visited[n];
        memset(visited,false,sizeof(visited));
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>&parent(n,-1);
        
        queue<int>q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
          int si=q.size();
            while(si--){
                int t=q.front();
                q.pop();
                
                for(auto i:graph[t]){
                    if(!visited[i]){
                        visited[i]=true;
                        parent[i]=t;
                        q.push(i);
                    }
                }
            }
        }
        
        vector<vector<int>>count(n,vector<int>(26,0));
        
        DFS(0,graph,labels,parent,count);
        
        vector<int>v;
        
        for(int i=0;i<count.size();i++)
            v.push_back(count[i][labels[i]-'a']);
        
        return v;
    }
};