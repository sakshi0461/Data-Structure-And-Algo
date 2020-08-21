class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int count=arr[0]-1;

if(k<=count)
   return k;

for(int i=1;i<arr.size();i++){
    int temp=count;
   count+=arr[i]-arr[i-1]-1;
   if(k<=count)
     return arr[i-1]+k-temp;    
}

        return arr[arr.size()-1]+k-count;
    }
};