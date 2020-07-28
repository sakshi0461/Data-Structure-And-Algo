class Solution {
public:
    bool issafe(int x,int y,int n,int m){
        if(x>=0 && y>=0 && x<n && y<m) return true;
        return false;
    }
    bool DFS(vector<vector<int>>&grid,vector<vector<bool>>&visited,int x,int y,int xa[],int ya[],int n,int m){
        visited[x][y]=true;
       bool out=true;
        for(int i=0;i<4;i++){
            int x0=x+xa[i],y0=y+ya[i];
            
            if(issafe(x0,y0,n,m) && grid[x0][y0]==0 && !visited[x0][y0]){
                if(x0==0 || x0==n-1 || y0==0 || y0==m-1)
                    out=false;
                out=out & DFS(grid,visited,x0,y0,xa,ya,n,m);
            }
        }
        
        return out;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        int xa[4]={0,0,-1,1};
        int ya[4]={-1,1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1)
                    continue;
                if(!grid[i][j] && !visited[i][j]){
                    if(DFS(grid,visited,i,j,xa,ya,n,m))
                        count++;
                }
            }
        }
        
        return count;
    }
};