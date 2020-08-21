class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(int i=0;i<coins.size();i++){
            if(coins[i]>amount) continue;
              dp[coins[i]]=1;
        }
        
        for(int i=1;i<=amount;i++){
            if(dp[i]==1) continue;
            
            for(int j=0;j<coins.size();j++)
              if(coins[j]<=i)
                  if(dp[i-coins[j]]!=INT_MAX)
                     dp[i]=min(dp[i],dp[coins[j]]+dp[i-coins[j]]);
        }
        
        if(dp[amount]==INT_MAX) return -1;
        
        return dp[amount];
    }
};