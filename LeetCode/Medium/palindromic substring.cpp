class Solution {
public:
    bool ispalin(string s){
        int st=0,e=s.length()-1;
        
        while(st<e){
            if(s[e]!=s[st])
                return false;
            st++;
            e--;
        }
        
        return true;
    }
    int count(string s,int start,int end,vector<vector<int>>&dp){
        
        if(dp[start][end]!=-1) return dp[start][end];
        
        if(start>end) return dp[start][end]=0;
        if(start==end) return dp[start][end]=1;
        
        int c=0;
        
        if(ispalin(s.substr(start,end-start+1)))
            c++;
        
        c+=count(s,start+1,end,dp)+count(s,start,end-1,dp)-count(s,start+1,end-1,dp); 
            
        return dp[start][end]=c;
    }
    int countSubstrings(string s) {
        
        // vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        // return count(s,0,s.length()-1,dp);
        
        int n=s.length();
        int dp[n][n];
        
        memset(dp,0,sizeof(dp));
         for (int i = 0; i < s.length(); i++) {
            dp[i][i] =1;
        }
        for(int start=n-1;start>=0;start--){
          for(int end=start+1;end<n;end++){
              if(dp[start][end]!=0) continue;
                  if(ispalin(s.substr(start,end-start+1)))
                      dp[start][end]++;
                  dp[start][end]+=dp[start+1][end]+dp[start][end-1]-dp[start+1][end-1];
          }   
        }
    
      return dp[0][n-1];
    }
};