class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>v;
        if(nums.size()<4) return v; 
        int i=0,j=1;
        
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
           int newtar=target-nums[i];
            bool hii=false;
            for(int fixed=i+1;fixed<nums.size()-2;fixed++){
                if(hii && nums[fixed]==nums[fixed-1]) continue;
                int j=fixed+1,k=nums.size()-1;
                int newtarr=newtar-nums[fixed];
               // tt=true;
                while(j<k){
                    if(nums[j]+nums[k]==newtarr){
                        vector<int>t={nums[i],nums[fixed],nums[j],nums[k]};
                        if(find(v.begin(),v.end(),t)==v.end())
                            v.push_back(t);
                        while(j<k && nums[j]==nums[j+1]) j++;
                        while(j<k && nums[k]==nums[k-1]) k--;
                        
                        j++;
                        k--;
                    }
                    else if(nums[j]+nums[k]>newtarr)
                        k--;
                    else
                        j++;
                }
            }
        }
        
        return v;
    }
};