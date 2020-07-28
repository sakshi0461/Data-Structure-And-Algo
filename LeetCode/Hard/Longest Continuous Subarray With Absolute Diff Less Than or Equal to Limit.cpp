class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int maxi=1;
        
        for(int j=0;j<nums.size();j++){
            if(j>0 && nums[j]==nums[j-1]) continue;
        long long int maxsofar=nums[j],minsofar=nums[j];
        int len=1;
        for(int i=j+1;i<nums.size();i++){
            maxsofar=max(maxsofar,(long long int)nums[i]);
            minsofar=min(minsofar,(long long int)nums[i]);
            if(abs(maxsofar-minsofar)<=(long long int)limit)
               len++;
            else
                break;
          } 
            maxi=max(maxi,len);
        }
        
        return maxi;
    }
};