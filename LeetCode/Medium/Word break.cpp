class Solution {
public:
//     //METHOD 1- RECURSIVE AND MEMOZIATION
    bool word(string s,vector<string>&v,int start,int end,int dp[][1001]){
        
        if(start>end) return false;
        
        if(dp[start][end]!=-1) return dp[start][end] ? true : false ; 
        
        if(find(v.begin(),v.end(),s.substr(start,end-start+1))!=v.end())
            return true;
        
        
        bool out=false;
        
        for(int k=start;k<end;k++){
            if(find(v.begin(),v.end(),s.substr(start,k-start+1))!=v.end()){
                out=out | word(s,v,k+1,end,dp);
            }
        }
        
        out ? dp[start][end]=1 : dp[start][end]=0;
        
        return out;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
       return word(s,wordDict,0,s.length()-1,dp);
    }
    
    //METHOD 2- TOP DOWN
     bool wordBreak(string s, vector<string>& v) {
        
         bool dp[s.size()+1];
         memset(dp,false,sizeof(dp));
         
         if(find(v.begin(),v.end(),"")!=v.end())
             dp[0]=true;
         
         for(int i=1;i<=s.size();i++){
             
             if(!dp[i] && find(v.begin(),v.end(),s.substr(0,i))!=v.end())
                 dp[i]=true;
             
             if(dp[i]){
                 
                 for(int j=i+1;j<=s.size();j++){
                     if(!dp[j] && find(v.begin(),v.end(),s.substr(i,j-i))!=v.end())
                       dp[j]=true;
                     
                 }
             }
         }
         
         return dp[s.size()];
    }
};








