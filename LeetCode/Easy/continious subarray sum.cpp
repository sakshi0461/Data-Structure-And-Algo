class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int prefix[nums.size()+1];
        prefix[0]=0;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=nums[i]+prefix[i];
            
            if(i>0 && prefix[i+1]==0 && k==0) return true;
            if(i>0 && k!=0 && prefix[i+1]%k==0) return true;
            
            for(int j=0;j<i;j++){
                if(k==0 && prefix[i+1]-prefix[j]==0) return true;
                if(k!=0 && (prefix[i+1]-prefix[j])%k==0)
                    return true;
            }
        }
    
        return false;
    }
};