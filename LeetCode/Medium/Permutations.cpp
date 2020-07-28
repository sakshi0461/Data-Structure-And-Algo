class Solution {
public:
    void permu(vector<int>&nums,vector<vector<int>>&v,int start){
       
        if(start==nums.size()){
            v.push_back(nums);
            return;
        }
        
       for(int i=start;i<nums.size();i++){
           swap(nums[start],nums[i]);
           permu(nums,v,start+1);
           swap(nums[start],nums[i]);
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        permu(nums,v,0);
        return v;
    }
};