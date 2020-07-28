int Solution::cntInc(vector<int> &A) {
    
    int n=A.size();
    int count=0;
    bool p=false;
     int dp[n];
    memset(dp,1,sizeof(dp));
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1]){
          dp[i]=1+dp[i-1];
        p=false;
        }
        else{
            p=true;
            if(i==1)
             count++;
            count+=(dp[i-1]*(dp[i-1]+1))/2;
            dp[i]=1;
        }
    }
    
    if(!p)
      count+=(dp[n-1]*(dp[n-1]+1))/2;
      
    return count;
}

