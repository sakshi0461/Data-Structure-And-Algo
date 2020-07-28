class Solution {
public:
 //MTHOD 1-USING HASHING   
   int findDuplicate(vector<int>& nums) {
        unordered_set<int>mp;
       for(int i=0;i<nums.size();i++)
         if(mp.find(nums[i])!=mp.end()) return nums[i];
         else mp.insert(nums[i]);
       return 0;
    }
 //METHOD 2-SORTING
 //METHOD 3-CYCLE DETECTION
  int findDuplicate(vector<int>& nums){
    int slow=nums[0],fast=nums[0];
    while(1){
      slow=nums[slow];
      fast=nums[nums[fast]];
      if(slow==fast)
        break;
    }
    slow=nums[0];
    while(slow!=fast){
      slow=nums[slow];
      fast=nums[fast];
    }
    return slow;
  }
};