class Solution {
public:
   bool isperfect(int n){
      if((int)sqrt(n)*(int)sqrt(n)==n)
        return true;
     return false;
    } 
   int numSquares(int n) {
       int dp[n+1];
       memset(dp,0,sizeof(dp));
      for(int i=1;i<=n;i++){
        if(isperfect(i)){
          dp[i]=1;
        }
        else{
        int mini=INT_MAX;
        for(int j=1;j<=i/2;j++)
           if(mini>dp[j]+dp[i-j])
              mini=dp[j]+dp[i-j];
         dp[i]=mini;
        }
      }
      return dp[n];
    }
};