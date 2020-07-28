class Solution {
public:
    int integerBreak(int n) {
        
      int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
           for(int k=1;k<=i/2;k++)
            dp[i]=max({dp[i],max(k,dp[k])*max(i-k,dp[i-k])});
        }
        
        return dp[n];
    }
};