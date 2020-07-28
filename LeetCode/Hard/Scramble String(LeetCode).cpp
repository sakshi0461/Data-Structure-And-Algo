class Solution {
public:
    bool check(string s1,string s2,unordered_map<string,bool>&dp){
         int end=s1.length();
        if(end==0) return true;
        if(end==1) return (s1==s2);
        
        if(dp.count(s1+s2))  return dp[s1+s2];
        
         if(s1==s2) return dp[s1+s2]=true;
        
      for(int mid=1;mid<end;mid++){
          string s11=s1.substr(0,mid);
          string s22=s2.substr(0,mid);
          string s12=s1.substr(mid,end-mid);
          string s21=s2.substr(mid,end-mid);
          
          if(check(s11,s22,dp)
              && check(s12,s21,dp))
           return dp[s1+s2]=true;
          
          string s23=s2.substr(end-mid,mid);
          string s24=s2.substr(0,end-mid);
          
        if(check(s11,s23,dp)
            && check(s12,s24,dp))
             return dp[s1+s2]=true;
       }
        
        return dp[s1+s2]=false;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool>dp;
        return check(s1,s2,dp);
    }
};
