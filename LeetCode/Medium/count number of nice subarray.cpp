class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0,ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0)
                nums[i]=1;
            else
                nums[i]=0;
            ans+=nums[i];
            count+=mp[ans-k];
            mp[ans]++;
        }
        
        return count;
    }
};