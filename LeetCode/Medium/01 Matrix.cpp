class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        int n=matrix.size(),m=matrix[0].size();
           
        vector<vector<int>>v(n,vector<int>(m,INT_MAX-10000));
        
        int xa[4]={1,-1,0,0};
        int ya[4]={0,0,1,-1};
        
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(matrix[i][j]==0)
                  v[i][j]=0;
              else{
                  if(i>0)
                      v[i][j]=min(v[i][j],1+v[i-1][j]);
                  if(j>0)
                      v[i][j]=min(v[i][j],1+v[i][j-1]);
              }
          }    
        }
        
        for(int i=n-1;i>=0;i--){
          for(int j=m-1;j>=0;j--){
              if(matrix[i][j]==0)
                  v[i][j]=0;
              else{
                  if(i+1<n)
                      v[i][j]=min(v[i][j],1+v[i+1][j]);
                  if(j+1<m)
                      v[i][j]=min(v[i][j],1+v[i][j+1]);
              }
          }    
        }
        
        return v;
    }
};