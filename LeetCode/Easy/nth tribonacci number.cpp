class Solution {
public:
    int tri(int n,vector<int>&dp){
         if(n==0) return dp[0]=0;
        if(n==1) return dp[1]=1;
        if(n==2) return dp[2]=1;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n]=tri(n-1,dp)+tri(n-2,dp)+tri(n-3,dp);
    }
    int tribonacci(int n) {
         vector<int>dp(38,-1);
          return tri(n,dp);
    }
};