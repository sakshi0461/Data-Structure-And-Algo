class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        
        unordered_map<int,vector<pair<int,int>>>graph;
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push(make_pair(0,0));
        vector<int>dist(N,INT_MAX);
        vector<bool>visited(N,false);
        dist[0]=0;
        
        while(!q.empty()){
          auto p=q.top();
            q.pop();
          if(visited[p.second]) continue;
          visited[p.second]=true;
            
            for(auto i:graph[p.second]){
                if(!visited[i.first]){
                    if(dist[p.second]+i.second+1<dist[i.first]){
                        dist[i.first]=dist[p.second]+i.second+1;
                        q.push(make_pair(dist[i.first],i.first));
                    }
                }
            }
        }
        
        int count=0;
        
        for(int i=0;i<N;i++){
            if(dist[i]<=M)
                count++;
        }
        
        for(int i=0;i<edges.size();i++){
            int a,b;
            if(dist[edges[i][0]]<=M)
                a=M-dist[edges[i][0]];
            else
                a=0;
            if(dist[edges[i][1]]<=M)
                b=M-dist[edges[i][1]];
            else
                b=0;
           // cout<<count<<" ";
            count+=min(edges[i][2],a+b);
        }
        
        return count;
    }
};