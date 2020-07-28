class Solution {
public:
    bool DFS1(bool visited[][1000],vector<vector<char>>&grid,int x,int y,int xa[],int ya[],int n,int m){
        visited[x][y]=true;
        
        bool out=true;
        for(int i=0;i<4;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            if(x0>=0 && y0>=0 && x0<n && y0<m && grid[x0][y0]=='O' && !visited[x0][y0]){
                out=out & DFS1(visited,grid,x0,y0,xa,ya,n,m);
            }
        }
        
        if(x==0 || x==n-1 || y==0 || y==m-1) return false;
        return out;
    }
    void DFS2(bool visited[][1000],vector<vector<char>>&grid,int x,int y,int xa[],int ya[],int n,int m){
        visited[x][y]=true;
        grid[x][y]='X';
        for(int i=0;i<4;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            if(x0>=0 && y0>=0 && x0<n && y0<m && !visited[x0][y0] && grid[x0][y0]=='O')
                DFS2(visited,grid,x0,y0,xa,ya,n,m);
        }
    }
    void solve(vector<vector<char>>& grid) {
         if(grid.size()==0) return;
        int n=grid.size(),m=grid[0].size();
      int xa[4]={0,0,1,-1};
      int ya[4]={1,-1,0,0};
        
        bool visited[1000][1000],visited2[1000][1000];
        memset(visited,false,sizeof(visited));
        memset(visited2,false,sizeof(visited2));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='O')
                  if(DFS1(visited,grid,i,j,xa,ya,n,m))
                      DFS2(visited2,grid,i,j,xa,ya,n,m);
            }
        }
    }
};