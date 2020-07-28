class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        set<pair<int,int>>s;
        
        for(int i=0;i<arr.size();i++){
           s.insert(make_pair(abs(arr[i]-x),i));
        }
        
        vector<int> v;
        
        auto it=s.begin();
        
        while(k-- && it!=s.end()){
            v.push_back(arr[it->second]);
            it++;
        }
        
        sort(v.begin(),v.end());
        
        return v;
    }
};