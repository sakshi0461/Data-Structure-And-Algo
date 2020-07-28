class Solution {
public:
     void subset(vector<int>&nums,int start,vector<vector<int>>&v){
        
       if(start==nums.size()){
            v.push_back(nums);
            return;
       }
        
        for(int i=start;i<nums.size();i++){
            if(i!=start && nums[i]==nums[start]) continue;
            swap(nums[start],nums[i]);
            subset(nums,start+1,v);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        subset(nums,0,v);
        return v;
    }
};