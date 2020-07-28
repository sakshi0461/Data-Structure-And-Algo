class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        
        int count=0;
        
        for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[i].size();j++){
               if(grid[i][j]==0) continue;
               count+=(4*grid[i][j]+2);
               if(j>0){
                 count-=(2*min(grid[i][j-1],grid[i][j]));
               }
               if(i>0){
                   count-=(2*min(grid[i][j],grid[i-1][j]));
               }
           }
        }
        
        return count;
    }
};