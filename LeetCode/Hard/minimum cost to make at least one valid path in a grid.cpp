class Solution {
public:
    //METHOD 1-HEAP
    int minCost(vector<vector<int>>& grid) {
        
        int xa[4]={0,0,1,-1};
        int ya[4]={1,-1,0,0};
        
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push(make_pair(0,make_pair(0,0)));
    
        
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            
            int x=p.second.first;
            int y=p.second.second;
            int cost=p.first;
            
             if(visited[x][y]) continue;
             visited[x][y]=true;
            
             if(x==grid.size()-1 && y==grid[0].size()-1)
                 return cost;
            
            for(int i=0;i<4;i++){
                int x0=x+xa[i];
                int y0=y+ya[i];
                
                if(x0>=0 && y0>=0 && x0<grid.size() && y0<grid[0].size()){
                    if(!visited[x0][y0]){
                        
                        if(i==grid[x][y]-1)
                            q.push(make_pair(cost,make_pair(x0,y0)));
                        else
                            q.push(make_pair(cost+1,make_pair(x0,y0)));
                        
                    }
                }
            }
        }
        
        return -1;
    }
    
    //METHOD 2-DEQUEUE
     int minCost(vector<vector<int>>& grid) {   
       
        
        int xa[4]={0,0,1,-1};
        int ya[4]={1,-1,0,0};
         
         deque<pair<int,pair<int,int>>>q;
         q.push_back(make_pair(0,make_pair(0,0)));
         
         vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
         
         while(!q.empty()){
             
             auto p=q.front();
             q.pop_front();
             
             int x=p.second.first;
             int y=p.second.second;
             int cost=p.first;
             
             if(visited[x][y]) continue;
             visited[x][y]=true;
            
             if(x==grid.size()-1 && y==grid[0].size()-1)
                 return cost;
             
             for(int i=0;i<4;i++){
                int x0=x+xa[i];
                int y0=y+ya[i];
                
                if(x0>=0 && y0>=0 && x0<grid.size() && y0<grid[0].size()){
                    if(!visited[x0][y0]){
                        if(i==grid[x][y]-1)
                            q.push_front(make_pair(cost,make_pair(x0,y0)));
                        else
                            q.push_back(make_pair(cost+1,make_pair(x0,y0)));
                    }
                }
            }
         }
         
         return -1;
     }
};