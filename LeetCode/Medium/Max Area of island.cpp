class Solution {
public:
    bool issafe(int x,int y,int n,int m){
        if(x>=0 && y>=0 && x<n && y<m)
            return true;
        return false;
    }
    void DFS(vector<vector<bool>>&visited,vector<vector<int>>grid,int x,int y,int n,int m,int xa[4],int ya[4],int &level){
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            if(issafe(x0,y0,n,m) && grid[x0][y0] && !visited[x0][y0]){
                level++;
                DFS(visited,grid,x0,y0,n,m,xa,ya,level);
          }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visited;
        for(int i=0;i<n;i++){
            vector<bool>temp(m,false);
            visited.push_back(temp);
        }
        
        int count=0;
        
        int xa[4]={0,0,1,-1};
        int ya[4]={1,-1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]){
                    int level=1;
                    DFS(visited,grid,i,j,n,m,xa,ya,level);
                    count=max(count,level);
                }
            }
        }
        
        return count;
    }
};