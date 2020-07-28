class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int dp[nums.size()];
        dp[0]=nums[0];
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i-1;j++)
                if(maxi<dp[j])
                    maxi=dp[j];
            dp[i]=maxi+nums[i];
        }
        
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
};