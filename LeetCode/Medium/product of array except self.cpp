class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>dp(nums.size(),1);
        vector<int>dp2(nums.size(),1);
        
        for(int i=1;i<nums.size();i++)
            dp[i]=dp[i-1]*nums[i-1];
        
        for(int i=nums.size()-2;i>=0;i--)
            dp2[i]=dp2[i+1]*nums[i+1];
        
        vector<int>v;
        
        for(int i=0;i<nums.size();i++)
            v.push_back(dp[i]*dp2[i]);
        
        return v;
    }
};