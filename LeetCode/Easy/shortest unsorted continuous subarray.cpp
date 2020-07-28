class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
       vector<int>v=nums;
        sort(v.begin(),v.end());
        int findex=0,index=1;
        bool p=false;
        for(int i=0;i<v.size();i++){
            if(v[i]==nums[i]) continue;
            if(!p){
                index=i;
                p=true;
            }
            findex=i;
        }
        
        return findex-index+1;
    }
};