class Solution {
public:
    //METHOD 1-RECURSIVE 
    bool funct(string s1,string s2,string s3,int i1,int i2,int i3){
       
        if(i3==s3.length() && i1==s1.length() && i2==s2.length()) return true;
        
        if(i3==s3.length() && (i1!=s1.length() || i2!=s2.length())) return false;
        
        if(s3[i3]==s1[i1] && s3[i3]!=s2[i2])
            return funct(s1,s2,s3,i1+1,i2,i3+1);
        if(s3[i3]!=s1[i1] && s3[i3]==s2[i2])
            return funct(s1,s2,s3,i1,i2+1,i3+1);
        
        if(s3[i3]==s1[i1] && s3[i3]==s2[i2])
            return funct(s1,s2,s3,i1+1,i2,i3+1) | funct(s1,s2,s3,i1,i2+1,i3+1);

        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
         return funct(s1,s2,s3,0,0,0);
    }
    //METHOD 2-MEMOZIATION
    bool funct(string s1,string s2,string s3,int i1,int i2,int i3,int dp[][100][200]){
        
        if(i3==s3.length() && i1==s1.length() && i2==s2.length()) {
            dp[i1][i2][i3]=1;
            return true;
        }
        
        if(i3==s3.length() && (i1!=s1.length() || i2!=s2.length())) {
           dp[i1][i2][i3]=0;
            return false;
        }
        
        if(dp[i1][i2][i3]!=-1){
            if(dp[i1][i2][i3]) return true;
            return false;
        }
        
        if(s3[i3]==s1[i1] && s3[i3]!=s2[i2]){
           bool out=funct(s1,s2,s3,i1+1,i2,i3+1,dp);
            if(out) dp[i1][i2][i3]=1;
            else dp[i1][i2][i3]=0;
            return out;
        }
        if(s3[i3]!=s1[i1] && s3[i3]==s2[i2]){
           bool out=funct(s1,s2,s3,i1,i2+1,i3+1,dp);
            if(out) dp[i1][i2][i3]=1;
            else dp[i1][i2][i3]=0;
            return out;
        }
        
        if(s3[i3]==s1[i1] && s3[i3]==s2[i2]){
           bool out=funct(s1,s2,s3,i1+1,i2,i3+1,dp) | funct(s1,s2,s3,i1,i2+1,i3+1,dp);
            if(out) dp[i1][i2][i3]=1;
            else dp[i1][i2][i3]=0;
            return out;
        }
          dp[i1][i2][i3]=0;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int dp[100][100][200];
        memset(dp,-1,sizeof(dp));
        return funct(s1,s2,s3,0,0,0,dp);
    }
    //METHOD 3-TOP DOWN APPROACH
    bool isInterleave(string s1, string s2, string s3) {
        int x=s1.length(),y=s2.length(),z=s3.length();
        bool dp[x+1][y+1][z+1];
        memset(dp,false,sizeof(dp));
        
        dp[s1.length()][s2.length()][s3.length()]=true;
        
        
        for(int i3=z;i3>=0;i3--){
           for(int i1=x;i1>=0;i1--){
              for(int i2=y;i2>=0;i2--){
                
                  if(i3==z && i2==y && i1==x) dp[i1][i2][i3]=true;
                  else if(i3==z && (i2!=y || i1!=x)) dp[i1][i2][i3]=false;
                  else{
                      
                      if(i1<x && i2<y){
                          if(s3[i3]==s1[i1] && s3[i3]==s2[i2])
                              dp[i1][i2][i3]=dp[i1+1][i2][i3+1] | dp[i1][i2+1][i3+1];
                          else if(s3[i3]==s1[i1])
                              dp[i1][i2][i3]=dp[i1+1][i2][i3+1];
                          else if(s3[i3]==s2[i2])
                              dp[i1][i2][i3]=dp[i1][i2+1][i3+1];
                          else
                              dp[i1][i2][i3]=false;
                      }
                      else if(i1<x){
                          if(s3[i3]==s1[i1])
                              dp[i1][i2][i3]=dp[i1+1][i2][i3+1];
                          else
                              dp[i1][i2][i3]=false;
                      }
                      else if(i2<y){
                          if(s3[i3]==s2[i2])
                              dp[i1][i2][i3]=dp[i1][i2+1][i3+1];
                          else
                              dp[i1][i2][i3]=false;
                      }
                      else
                          dp[i1][i2][i3]=false;
                  }
              }
           }
        }
        
        return dp[0][0][0];
    }
};