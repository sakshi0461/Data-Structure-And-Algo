class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informtime) {
        
        unordered_map<int,vector<int>>graph;
        
        for(int i=0;i<manager.size();i++)
            graph[manager[i]].push_back(i);
        
        bool visited[n];
        memset(visited,false,sizeof(visited));
        
        queue<pair<int,int>>q;
        q.push(make_pair(0,headID));
        visited[headID]=true;
        
        int maxi=0;
        
        while(!q.empty()){
            int si=q.size();
            while(si--){
                pair<int,int>p=q.front();
                q.pop();
                maxi=max(maxi,p.first);
                
                for(auto i:graph[p.second]){
                    if(!visited[i]){
                        visited[i]=true;
                        q.push(make_pair(p.first+informtime[manager[i]],i));
                    }
                }
            }
        }
        
        return maxi;
    }
};