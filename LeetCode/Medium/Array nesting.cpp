class Solution {
public:
    int send(vector<int>&v,int dp[],int index,vector<bool>&visited){
        if(visited[index]) return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        visited[index]=true;
        return dp[index]=1+send(v,dp,v[index],visited);
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        vector<bool>visited(n,false);
        memset(dp,-1,sizeof(dp));
        
      for(int i=0;i<n;i++){
         if(!visited[i])
          send(nums,dp,i,visited);
      }
        int d=*max_element(dp,dp+n);
        
        return d;
    }
};