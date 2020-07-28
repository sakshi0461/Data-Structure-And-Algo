class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        bitset<20001>b;
        b[0]=1;
        for(int i=0;i<nums.size();i++){
            b = b | (b<<nums[i]);
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        
        return b[sum/2]==1;
    }
};