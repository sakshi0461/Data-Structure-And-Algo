class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        
        dp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++)
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
        
        return *max_element(dp,dp+nums.size());
    }
    //METHOD 2- PREFIX SUM
    int maxSubArray(vector<int>&nums){
        int prefix[nums.size()],dp[nums.size()];
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            prefix[i]=prefix[i-1]+nums[i];
        
        for(int i=0;i<nums.size();i++){
           int maxi=prefix[i];
            for(int j=i-1;j>=0;j--)
                if(maxi<prefix[i]-prefix[j])
                    maxi=prefix[i]-prefix[j];
            dp[i]=maxi;
        }
        
        return *max_element(dp,dp+nums.size());
    }
};
