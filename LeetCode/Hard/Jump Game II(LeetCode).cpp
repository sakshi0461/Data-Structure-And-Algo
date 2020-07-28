class Solution {
public:
  //METHOD 1
    int minJumps(vector<int>&nums, int n) 
{ 
    int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=INT_MAX;
        dp[0]=0;
        
        for(int i=0;i<n;i++){
          int limit=min(n-1,nums[i]+i);
            for(int j=i+1;j<=limit;j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        
        return dp[n-1];
}
    //METHOD 2
    int minJumps(vector<int>&nums,int n){
        int maxreach=nums[0];
        int step=nums[0],jumpp=0;
        
        for(int i=1;i<n;i++){
            maxreach=max(maxreach,i+nums[i]);
            step--;
            if(i==n-1)
                return jumpp+1;
            if(step==0){
                jumpp++;
                if(i>=maxreach)
                    return 0;
                else
                    step=maxreach-i;
            }
        }
        return 0;
    }
    int jump(vector<int>& nums) {
        return minJumps(nums,nums.size());
    }
};