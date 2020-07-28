class Solution {
public:
    //METHOD 1- RECURSIVE AND MEMOZIATION
    bool fun(string s,string p,int n,int m,int dp[][1001]){
        if(n==s.length() && m==p.length()){
            dp[n][m]=1;
            return true;
        }
        
        if((n!=s.length() && m==p.length())){
            dp[n][m]=0;
            return false;
        }
        
        if(dp[n][m]!=-1){
            if(dp[n][m])
                return true;
             return false;
        }
        
        if(p[m]=='?'){
           if(n==s.length()){
               dp[n][m]=0;
               return false;
           }
            bool o=fun(s,p,n+1,m+1,dp);
            if(o) dp[n][m]=1;
            else dp[n][m]=0;
            return o;
        }
        else if(p[m]>='a' && p[m]<='z'){
            if(n==s.length()){
             dp[n][m]=0;
                return false;
            }
            if(s[n]==p[m]){
               bool o=fun(s,p,n+1,m+1,dp);
                 if(o) dp[n][m]=1;
                 else dp[n][m]=0;
                return o;
            }
            else{
               dp[n][m]=0;
                return false;
            }
        }
        
        bool out=false;
        
        for(int k=0;k<=s.length()-n;k++){
           if(m==p.length()) {
                dp[n][m]=0;
               return false;
           }
            out= out | fun(s,p,n+k,m+1,dp);
        }
        if(out)
            dp[n][m]=1;
        else
            dp[n][m]=0;
        return out;
    }
    bool isMatch(string s, string p) {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return fun(s,p,0,0,dp);
    }
    //METHOD 2-TOP DOWN
     bool isMatch(string s,string p){
         int n=s.length();
         int m=p.length();
         bool dp[n+1][m+1];
         memset(dp,false,sizeof(dp));
         
         dp[0][0]=true;
         
         for(int i=1;i<m+1;i++)
             if(p[i-1]=='*')
                 dp[0][i]=dp[0][i-1];
         
         for(int i=1;i<n+1;i++)
             dp[i][0]=false;
         
         for(int i=1;i<n+1;i++){
             for(int j=1;j<m+1;j++){
                 if(p[j-1]=='*')
                     dp[i][j]=dp[i][j-1] || dp[i-1][j];
                 else if(p[j-1]>='a' && p[j-1]<='z'){
                    if(s[i-1]==p[j-1])
                        dp[i][j]=dp[i-1][j-1];
                     else
                         dp[i][j]=false;
                 }
                 else if(p[j-1]=='?')
                     dp[i][j]=dp[i-1][j-1];
             }
         }
         
         return dp[n][m];
     }
};