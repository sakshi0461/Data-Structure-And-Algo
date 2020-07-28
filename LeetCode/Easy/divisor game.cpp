class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N+1];
        memset(dp,false,sizeof(dp));
        
        for(int i=2;i<=N;i++){
            for(int j=1;j<=i/2;j++){
                if(i%j==0)
                    if(!dp[i-j]){
                        dp[i]=true;
                        break;
                    } 
            }
        }
        return dp[N];
   }
};