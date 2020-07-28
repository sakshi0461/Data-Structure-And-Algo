int LCS(string s1,string s2){
    int dp[s1.length()+1][s2.length()+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<s1.length()+1;i++){
        for(int j=0;j<s2.length()+1;j++){
            if(i==0 || j==0)
              dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
              dp[i][j]=1+dp[i-1][j-1];
            else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[s1.length()][s2.length()];
}
vector<int> Solution::maxLCS(string s) {
    
    int maxi=0,index=0;
    for(int i=0;i<s.length()-1;i++){
        string s1=s.substr(i+1,s.length()-1-i);
        reverse(s1.begin(),s1.end());
        int d=LCS(s.substr(0,i+1),s1);
        if(maxi<d){
            maxi=d;
            index=i;
        }
    }
    
    return {index+1,maxi};
}
