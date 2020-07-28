class Solution {
public:
    //METHOD 1-RECURSIVE
    int funct(vector<int>&nums,int start,int end){
        if(start>end) return 0;
        if(start==end) return nums[start];
        
        return max(nums[start]+min(funct(nums,start+2,end),funct(nums,start+1,end-1)),
                   nums[end]+min(funct(nums,start+1,end-1),funct(nums,start,end-2)));
        
    }
    bool PredictTheWinner(vector<int>& nums) {
      int a=funct(nums,0,nums.size()-1);
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        if(a>=sum-a) 
            return true;
        return false;
    }
    //METHOD 2- TOP DOWN
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int dp[nums.size()][nums.size()];
        memset(dp,0,sizeof(dp));
        
        for(int s=n-1;s>=0;s--){
            for(int e=s;e<n;e++){
                int a=INT_MAX,b=INT_MAX,c=INT_MAX;
                if(s>e) dp[s][e]=0;
                if(s==e) dp[s][e]=nums[s];
                else{
                    if(s+2<n)
                        a=dp[s+2][e];
                    if(s+1<n && e-1>=0)
                        b=dp[s+1][e-1];
                    if(e-2>=0)
                        c=dp[s][e-2];
                    dp[s][e]=max(nums[s]+ min(a,b)
                                ,nums[e]+ min(b,c)
                                );
                }
            }
        }
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        if(dp[0][n-1]>=sum-dp[0][n-1])
            return true;
        return false;
        
    }
};