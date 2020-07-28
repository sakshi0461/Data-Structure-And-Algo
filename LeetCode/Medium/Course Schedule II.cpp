class Solution {
public:
//     //METHOD-1 DFS
//         bool cycle(unordered_map<int,vector<int>>graph,int v){
//         int indegree[v];
//         memset(indegree,0,sizeof(indegree));
//         stack<int>s;
//         for(int i=0;i<v;i++){
//             for(auto j:graph[i])
//                 indegree[j]++;
//         }
        
//         for(int i=0;i<v;i++)
//             if(indegree[i]==0)
//                 s.push(i);
        
//         int count=0;
        
//         while(!s.empty()){
//             int t=s.top();
//             s.pop();
//             count++;
//             for(int j=0;j<graph[t].size();j++){
//                     int v=graph[t][j];
//                     indegree[v]--;
//                     if(indegree[v]==0)
//                         s.push(v);
//             }
//         }
        
//         if(count==v)
//             return false;
//         return true;
//     }
//     void topologicalsort(stack<int>&s,unordered_map<int,vector<int>>graph,bool visited[],int src){
        
//         visited[src]=true;
        
//         for(int j=0;j<graph[src].size();j++){
//             int v=graph[src][j];
//             if(!visited[v])
//                 topologicalsort(s,graph,visited,v);
//         }
        
//         s.push(src);
//         return;
//     }
//     vector<int> findOrder(int V, vector<vector<int>>& pre) {
        
//         unordered_map<int,vector<int>>graph;
        
//         for(int i=0;i<pre.size();i++)
//             graph[pre[i][1]].push_back(pre[i][0]);
        
//         vector<int> arr;
        
//         if(cycle(graph,V))
//             return arr;
        
//          stack<int>sta;
//         bool visited[V];
//         memset(visited,false,sizeof(visited));
        
//         for(int i=0;i<V;i++)
//             if(!visited[i])
//               topologicalsort(sta,graph,visited,i);
        
//         while(!sta.empty()){
//             arr.push_back(sta.top());
//             sta.pop();
//         }
        
//         return arr;
//     }
     //METHOD 2-INDEGREE
     bool cycle(unordered_map<int,vector<int>>graph,int v,vector<int>&arr){
         int indegree[v];
        memset(indegree,0,sizeof(indegree));
         queue<int>s;
        for(int i=0;i<v;i++){
            for(auto j:graph[i])
                indegree[j]++;
        }
        
        for(int i=0;i<v;i++)
            if(indegree[i]==0)
                s.push(i);
         
         int count=0;
        
        while(!s.empty()){
            int t=s.front();
            s.pop();
            arr.push_back(t);
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
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        
        unordered_map<int,vector<int>>graph;
        
        for(int i=0;i<pre.size();i++)
            graph[pre[i][1]].push_back(pre[i][0]);
        
        vector<int> arr;
        
        if(cycle(graph,V,arr))
            return {};
        
        return arr;
    }
};