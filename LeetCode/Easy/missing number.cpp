class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xorr=0,xorr2=0;
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
            xorr2=xorr2^i;
        }
        
        xorr2=xorr2^nums.size();
        
        return xorr^xorr2;
    }
};