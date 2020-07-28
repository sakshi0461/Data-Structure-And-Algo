class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size()==0)
           return 0;
        int i=1,j=0;
        while(i<nums.size()){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            }
            i++;
        }
        return j+1;
    }
};