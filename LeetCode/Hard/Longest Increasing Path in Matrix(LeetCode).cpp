class Solution {
public:
    bool issafe(int x,int y,int n,int m){
        if(x>=0 && y>=0 && x<n && y<m) return true;
        return false;
    }
    void DFS(vector<vector<int>>&matrix,vector<vector<int>>&dp,vector<vector<bool>>&visited,int x,int y,int n,int m,int xa[],int ya[]){
        
        visited[x][y]=true;
        
        int maxi=0;
        for(int i=0;i<4;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            if(issafe(x0,y0,n,m) && matrix[x0][y0]>matrix[x][y]){// && !visited[x0][y0]){
                if(visited[x0][y0]){
                    maxi=max(maxi,dp[x0][y0]);
                    continue;
                }
                DFS(matrix,dp,visited,x0,y0,n,m,xa,ya);
                maxi=max(maxi,dp[x0][y0]);
            }
        }
        
        dp[x][y]+=maxi;
       // cout<<" dp "<<x<<" "<<y<<" "<<dp[x][y]<<" dp ";
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        int xa[4]={0,0,1,-1};
        int ya[4]={1,-1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                  //  cout<<i<<" "<<j<<"  ";
                    DFS(matrix,dp,visited,i,j,n,m,xa,ya);
                  //  cout<<"\n";
              }
           }
        }
        int maxi=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
            //  cout<<dp[i][j]<<" ";
                if(maxi<dp[i][j])
                    maxi=dp[i][j];
            }
        
        return maxi;
    }
};