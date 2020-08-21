class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int dirx[4]={0,0,1,-1};
        int diry[4]={1,-1,0,0};
        
        int peri=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1){
                   
                   peri+=4;
                   
                   for(int k=0;k<4;k++){
                       int x0=i+dirx[k];
                       int y0=j+diry[k];
                       
                       if(x0>=0 && y0>=0 && x0<n && y0<m)
                           if(grid[x0][y0]==1)
                             peri--;        
                   }
               }        
            }
        }
        
        return peri;
    }
};