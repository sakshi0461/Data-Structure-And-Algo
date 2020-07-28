class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int step=nums[0];
        int maxstep=nums[0];
        int jump=0;
        
        for(int i=1;i<nums.size();i++){
            if(step==0) return false;
            step--;
            maxstep=max(maxstep,nums[i]+i);
            
            if(step==0){
                jump++;
                step=maxstep-i;
            }
        }
        
        return true;
    }
};