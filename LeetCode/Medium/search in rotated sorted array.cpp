class Solution {
public:
    //METHOD 1
    int pos(vector<int>&nums){
        int n=nums.size();
        int i=0,j=n-1;
        if(n==1) return 0;
        
        while(i<=j){
            
            int mid=i+(j-i)/2;
            
            if(mid<n-1 && nums[mid]>nums[mid+1])
                return mid;
            if(mid>0 && nums[mid]<nums[mid-1])
                return mid-1;
            if(nums[i]>nums[mid])
                j=mid-1;
            else
                i=mid+1;
        }
            return n-1;
    }
    int bsearch(vector<int>&nums,int start,int end,int tar){
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid]==tar)
                return mid;
            else if(nums[mid]>tar)
                end=mid-1;
            else
                start=mid+1;
        }
        
        return -1;
    }
    //METHOD 2
    int bbsearch(vector<int>&nums,int tar){
        
        int start=0,end=nums.size()-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid]==tar)
                return mid;
            else if(nums[mid]<tar){
            
              if(nums[start]<=nums[mid])
                  start=mid+1;
              else{
                 if(tar>=nums[start])
                     end=mid-1;
                 else
                     start=mid+1;
              }
            }
            else{
                if(nums[start]<=nums[mid]){
                    if(tar>=nums[start])
                        end=mid-1;
                    else
                        start=mid+1;
                }
                else
                    end=mid-1;
            }
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
       if(nums.size()==0) return -1;
        return bbsearch(nums,target);
        // int peak=pos(nums);
        // cout<<peak<<" ";
        // if(target>=nums[0])
        //     return bsearch(nums,0,peak,target);
        // return bsearch(nums,peak+1,nums.size()-1,target);
    }
};