class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>v;
        int i=0;
        while(i<nums.size()){
           if(mp.find(target-nums[i])!=mp.end()){
               if(mp[target-nums[i]]!=i){
               v.push_back(i);
               v.push_back(mp[target-nums[i]]);
               break;
              }
           }
            mp[nums[i]]=i;
            i++;
        }
        return v;
    }
};