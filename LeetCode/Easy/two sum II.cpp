class Solution {
public:
   //METHOD 1
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int>v;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(numbers[i]+numbers[j]>target)
                j--;
            else
                i++;
        }
        return v;
    }
    //METHOD 2 BINARY SEARCH
     int binarysearch(vector<int>&numbers,int target,int i){
         int start=0,end=i-1;
         while(start<=end){
             int mid=start+(end-start)/2;
             if(numbers[mid]==target)
                 return mid;
             else if(numbers[mid]>target)
                 end=mid-1;
             else
                 start=mid+1;
         }
         return -1;
     }
     vector<int> twoSum(vector<int>& numbers, int target) {
     vector<int>v;
         for(int i=0;i<numbers.size();i++){
           int x=binarysearch(numbers,target-numbers[i],i);
           //  cout<<x<<" ";
           if(x!=-1){
               v.push_back(x+1);
               v.push_back(i+1);
              return v;
           }
       }
         return v;
     }
};