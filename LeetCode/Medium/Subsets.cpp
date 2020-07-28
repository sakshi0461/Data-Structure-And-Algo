class Solution {
public:
    void sub(vector<int>&nums,int start,vector<vector<int>>&v,vector<int>temp){
        v.push_back(temp);
        
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            sub(nums,i+1,v,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        if(nums.size()==0) return v;
        
        sub(nums,0,v,temp);
        
        return v;
    }
};