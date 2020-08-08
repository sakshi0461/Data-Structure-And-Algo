class Solution {
public:
    //METHOD 1-DFS
    void DFS(vector<vector<int>>grid,int x,int y,int tx,int ty,int xa[],int ya[],int &count){
        
        if(x==tx && y==ty){
            count++;
            return;
        }
        
        int d=grid[x][y];
        
        grid[x][y]=1;
        
        for(int i=0;i<2;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            
            if(x0>=0 && y0>=0 && x0<grid.size() && y0<grid[0].size())
                if(grid[x0][y0]!=1)
                    DFS(grid,x0,y0,tx,ty,xa,ya,count);
        }
        
        grid[x][y]=d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        
        if(grid[0][0]==1 || grid[n][m]==1) return 0;
        
        int xa[2]={1,0};
        int ya[2]={0,1};
        
        int count=0;
        
        DFS(grid,0,0,n,m,xa,ya,count);
        
        return count;
    }
    //METHOD 2-DP
    int uniquePathsWithObstacles(vector<vector<int>>&obs){
        int r=obs.size(),c=obs[0].size();
        if(r==0||c==0) return 0;
        if(obs[0][0]==1||obs[r-1][c-1]) return 0; 
          
        obs[0][0]=1;
        
        for(int i=1;i<c;i++)
           { 
            if(obs[0][i]) obs[0][i]=0; //obstacle
            else obs[0][i]=obs[0][i-1];
           }
         
        for(int i=1;i<r;i++)
           { 
            if(obs[i][0]) obs[i][0]=0; //obstacle
            else obs[i][0]=obs[i-1][0];
           }

        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(obs[i][j]) obs[i][j]=0;
                else
                    obs[i][j]=obs[i-1][j]+obs[i][j-1];
            }
        }
        return obs[r-1][c-1];
    }
};