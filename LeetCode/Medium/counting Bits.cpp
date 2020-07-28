class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        if(num==0) return dp;
        dp[0]=0;
        dp[1]=1;
        int k=0;
        for(int i=2;i<=num;i++){
            if(i==pow(2,k+1)){
                dp[i]=1;
                k++;
            }
            else{
                int j=pow(2,k);
                dp[i]=dp[j]+dp[i-j];
            }
        }
        
        return dp;
    }
};