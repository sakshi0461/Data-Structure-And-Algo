class Solution {
public:
    int burst(vector<int>&nums,int start,int end,vector<vector<int>>&dp){
        if(start>end) return 0;
        
        if(dp[start][end]!=-1) return dp[start][end];
        //Considering ith ballons to be last burst ballon
        int sum=0;
        
        for(int i=start;i<=end;i++)
        sum=max(sum,nums[start-1]*nums[i]*nums[end+1] + burst(nums,start,i-1,dp) + burst(nums,i+1,end,dp));
        
        return dp[start][end]=sum;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
       return burst(nums,1,nums.size()-2,dp);
    }
};