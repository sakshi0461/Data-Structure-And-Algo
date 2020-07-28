class Solution {
public:
//METHOD 1-NAIVE
    bool isSubsequence(string s, string t) {
       int k=0;
        bool out=false;
        
        for(int i=0;i<s.length();i++){
            for(int j=k;j<t.length();j++)
                if(s[i]==t[j]){
                    k=j+1;
                    out=true;
                    break;
                }
            if(!out)
                return false;
            out=false;
        }
        return true;
    }
 //METHOD 2-RECURSIVE
     bool subseq(string x,string y,int n,int m){
         if(n==0) return true;
         if(m==0) return false;
         if(x[n-1]==y[m-1])
             return subseq(x,y,n-1,m-1);
         else
             return subseq(x,y,n,m-1);
     }
    bool isSubsequence(string s, string t) {
        return subseq(s,t,s.length(),t.length());
    }
//METHOD 3-DP
    bool isSubsequence(string s, string t) {
        bool dp[s.length()+1][t.length()+1];
        memset(dp,false,sizeof(dp));
        
        for(int i=0;i<s.length()+1;i++)
            dp[i][0]=false;
        for(int i=0;i<t.length()+1;i++)
            dp[0][i]=true;
        
        for(int i=1;i<s.length()+1;i++){
            for(int j=1;j<t.length()+1;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
        return dp[s.length()][t.length()];
    }
};