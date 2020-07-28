class Solution {
public:
    int LCS(string x,string y,int n,int m,vector<vector<int>>&dp){
       if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(n==0 || m==0) 
            return dp[n][m]=0;
        
        if(x[n-1]==y[m-1])
           return dp[n][m]=1+LCS(x,y,n-1,m-1,dp);
        
           return dp[n][m]=max(LCS(x,y,n-1,m,dp),LCS(x,y,n,m-1,dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        
        // LCS(text1,text2,text1.length(),text2.length(),dp);
        
        for(int i=0;i<text1.length()+1;i++){
            for(int j=0;j<text2.length()+1;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
};