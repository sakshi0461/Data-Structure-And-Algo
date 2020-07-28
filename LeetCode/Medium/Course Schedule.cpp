class Solution {
public:
    //CLYCLE USING RECURSION
    bool cycle(unordered_map<int,vector<int>>graph,int src,bool visited[]){
        
        for(int i=0;i<graph[src].size();i++){
            if(!visited[graph[src][i]-1]){
               visited[graph[src][i]-1]=true;
                if(cycle(graph,graph[src][i],visited))
                    return true;
               visited[graph[src][i]-1]=false;
            }
            else return true;
        }
        
        return false;
    }
    //CYCLE USING COLOR
    bool DFSUtil(unordered_map<int,vector<int>>graph,int src,int visited[]){
        visited[src]=-1;
    for (int i=0;i<graph[src].size();i++) {
        int v=graph[src][i];
        if (visited[v]==-1)
            return true;
        if (visited[v]==0 && DFSUtil(graph,v,visited)) 
          return true; 
    } 
    visited[src] =1; 
    return false;
    }
    bool cycle(unordered_map<int,vector<int>>graph,int v){
         int visited[v];
       for(int i=0;i<v;i++)
           visited[i]=0;
        
    for (int i = 0; i < v; i++)
        if(visited[i]==0)
           if (DFSUtil(graph,i,visited)) 
              return true;
  
    return false; 
    }
    //METHOD 3-INDEGREE METHOD
    bool cycle(unordered_map<int,vector<int>>graph,int v){
        int indegree[v];
        memset(indegree,0,sizeof(indegree));
        stack<int>s;
        for(int i=0;i<v;i++){
            for(auto j:graph[i])
                indegree[j]++;
        }
        
        for(int i=0;i<v;i++)
            if(indegree[i]==0)
                s.push(i);
        
        int count=0;
        
        while(!s.empty()){
            int t=s.top();
            s.pop();
            count++;
            for(int j=0;j<graph[t].size();j++){
                    int v=graph[t][j];
                    indegree[v]--;
                    if(indegree[v]==0)
                        s.push(v);
            }
        }
        
        if(count==v)
            return false;
        return true;
    }
    bool canFinish(int V, vector<vector<int>>& pre) {
       unordered_map<int,vector<int>>graph(V);

        // for(int i=0;i<pre.size();i++)
        //   graph[pre[i][0]].push_back(pre[i][1]);
        for(int i=0;i<pre.size();i++)
          graph[pre[i][1]].push_back(pre[i][0]);
        return !cycle(graph,V);
    }
};