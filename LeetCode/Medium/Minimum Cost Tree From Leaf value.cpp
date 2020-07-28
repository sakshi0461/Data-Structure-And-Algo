class Solution {
public:
    //METHOD1- MCM FORMAT
    int funct(vector<int>&arr,int start,int end,int dp[][50]){
        if(start>=end) return 0;
    
         if(dp[start][end]!=-1) return dp[start][end];
        
        int sum=0,mini=INT_MAX;
        
        for(int k=start;k<end;k++){
            int l=*max_element(arr.begin()+start,arr.begin()+k+1);
            int r=*max_element(arr.begin()+k+1,arr.begin()+end+1);

            sum=(l*r)+ funct(arr,start,k,dp) + funct(arr,k+1,end,dp);
       
            if(mini>sum && sum>0)
                mini=sum;
        }
        
        return dp[start][end]=mini;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int dp[50][50];
        memset(dp,-1,sizeof(dp));
        return funct(arr,0,arr.size()-1,dp);
    }
};