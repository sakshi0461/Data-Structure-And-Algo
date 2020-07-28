class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int dp[nums.size()+1];
        memset(dp,0,sizeof(dp));
        int maxii=INT_MIN;
        
        deque<int>q;
        
        for(int i=1;i<nums.size()+1;i++){
            
            while(!q.empty() && q.front()<i-k)
                q.pop_front();
            
            int maxi;
            if(q.size()==0)
                maxi=0;
            else
                maxi=dp[q.front()];
            
            dp[i]=max(nums[i-1],maxi+nums[i-1]);
            
            while(!q.empty() && dp[i]>dp[q.back()])
               q.pop_back();
            
            q.push_back(i);
            
            if(maxii<dp[i])
                maxii=dp[i];
            
        }
        return maxii;
    }
};