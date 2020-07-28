class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        
        for(int i=0;i<arr1.size();i++)
            mp[arr1[i]]++;
        
        vector<int>v;
        
        for(int i=0;i<arr2.size();i++){
               while(mp[arr2[i]]!=0){
                   v.push_back(arr2[i]);
                   mp[arr2[i]]--;
               }
        }
        
        for(auto j:mp){
            while(j.second!=0){
                v.push_back(j.first);
                j.second--;
            }
        }
        
        return v;
    }
};