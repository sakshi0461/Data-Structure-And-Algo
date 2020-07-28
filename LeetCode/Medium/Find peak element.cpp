class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 0;
        
        int i=0,j=n-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            if((mid==0 && nums[mid]>nums[mid+1]) || (mid==n-1 && nums[mid]>nums[mid-1]))
                return mid;
            if(mid>0 && mid<n-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else{
                if(mid<n-1 && nums[mid]<nums[mid+1])
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        
        return -1;
    }
};