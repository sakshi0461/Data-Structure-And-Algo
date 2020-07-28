class Solution {
public:
    void subset(vector<int>&nums,vector<vector<int>>&v,int start,vector<int>temp){
        
        if(find(v.begin(),v.end(),temp)==v.end())
            v.push_back(temp);
        
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            subset(nums,v,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>t;
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        subset(nums,v,0,t);
        return v;
    }
};