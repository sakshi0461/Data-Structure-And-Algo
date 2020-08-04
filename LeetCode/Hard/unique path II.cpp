class Solution {
public:
    int find(vector<vector<int>>grid,int x,int y,int xa[],int ya[],int t,int c){
        
        if(grid[x][y]==2 && c==t+1)
            return 1;
        
        int count=0;
        
        grid[x][y]=-1;
            
        for(int i=0;i<4;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            
            if(x0>=0 && y0>=0 && x0<grid.size() && y0<grid[0].size()){
                if(grid[x0][y0]!=-1){
                 count+=find(grid,x0,y0,xa,ya,t,c+1);
                }
            }
        }
        
        grid[x][y]=0;
        
        return count;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int count;
        int xa[4]={1,-1,0,0};
        int ya[4]={0,0,1,-1};
        int x,y,c=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
                if(grid[i][j]==-1)
                    c++;
            }
        }
        
        count=find(grid,x,y,xa,ya,grid.size()*grid[0].size()-2-c,0);
        
        return count;
    }
};