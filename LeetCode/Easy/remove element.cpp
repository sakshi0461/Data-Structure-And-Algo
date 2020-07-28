class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int count=0,i=0,j=0;
      
        while(j<nums.size()){
          if(nums[j]!=val){
             nums[i]=nums[j];
              i++;
          }
            j++;
        }
    //OR
        while(i<nums.size()){
            if(nums[i]==val){
                nums[i]=nums[j];
                j--;
            }
            else
                i++;
        }
        return i;
    }
};