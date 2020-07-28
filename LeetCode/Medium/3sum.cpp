class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    
        int fixed=0;
        
        vector<vector<int>>v;
        
        while(fixed<nums.size()){
            if(fixed>0 && nums[fixed]==nums[fixed-1]) {
                fixed++;    
                continue;
            }
            int i=fixed+1,j=nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]+nums[fixed]==0){
                    v.push_back({nums[i],nums[j],nums[fixed]});
                    while (i<j && nums[i]==nums[i+1]) i++;
                    while (j>i && nums[j]==nums[j-1]) j--;
                    i++; j--;
                }
                else if(nums[i]+nums[j]+nums[fixed]>0)
                    j--;
                else
                    i++;
            }
            fixed++;
        }
        return v;
    }
};