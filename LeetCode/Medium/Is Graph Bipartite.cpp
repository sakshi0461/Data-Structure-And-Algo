class Solution {
public:
    bool BFS(vector<int>&color,vector<bool>&visited,unordered_map<int,vector<int>>&graph,int src){
        color[src]=0;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        
        while(!q.empty()){
            int t=q.front();
            q.pop();
            int c=color[t];
            for(int i=0;i<graph[t].size();i++){
                int e=graph[t][i];
                if(!visited[e]){
                    visited[e]=true;
                    color[e]=1-c;
                    q.push(e);
                }
                else{
                    if(color[e]==c)
                        return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>&mp) {
        int n=mp.size();
        unordered_map<int,vector<int>>graph(n);
        for(int i=0;i<n;i++)
            graph[i]=mp[i];
        
        vector<int>color(n,-1);
        vector<bool>visited(n,false);
       
        for(int i=0;i<n;i++)
            if(!visited[i])
                if(!BFS(color,visited,graph,i))
                    return false;
        
        return true;
    }
};