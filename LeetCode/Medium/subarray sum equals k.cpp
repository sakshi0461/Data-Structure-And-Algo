class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        
        unordered_map<int,vector<int>>mp;
        
        int sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)
                count++;
            if(mp.find(sum-k)!=mp.end())
                count+=mp[sum-k].size();
             mp[sum].push_back(i);
        }
        
        return count;
    }
};