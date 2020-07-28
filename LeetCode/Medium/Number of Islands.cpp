class Solution {
public:
    void DFS(vector<vector<char>>&grid,bool visited[][1000],int xa[],int ya[],int x,int y,int n,int m){
          visited[x][y]=true;
        for(int i=0;i<4;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            if(x0>=0 && y0>=0 && x0<n && y0<m && grid[x0][y0]=='1' && !visited[x0][y0])
                DFS(grid,visited,xa,ya,x0,y0,n,m);
        }
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int n=grid.size(),m=grid[0].size();
      int xa[4]={0,0,1,-1};
      int ya[4]={1,-1,0,0};
        
        bool visited[1000][1000];
        memset(visited,false,sizeof(visited));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    DFS(grid,visited,xa,ya,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};