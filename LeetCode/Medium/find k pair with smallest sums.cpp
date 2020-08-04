#define ppi pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>v;
        
        if(nums1.size()==0 || nums2.size()==0) return v;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        set<pair<int,int>>s;
        priority_queue<ppi,vector<ppi>,greater<ppi>>minheap;
        
        minheap.push(make_pair(nums1[0]+nums2[0],make_pair(0,0)));
        s.insert(make_pair(0,0));
        
        int i=0;
        while(i<k && !minheap.empty()){
            
            ppi temp=minheap.top();
            minheap.pop();
            
            int j=temp.second.first;
            int l=temp.second.second;
            
            v.push_back({nums1[j],nums2[l]});
            
            auto d=s.find(make_pair(j,l));
            s.erase(d);
            d=s.find(make_pair(j+1,l));
            
            if(d==s.end() && j<nums1.size()-1){
               minheap.push(make_pair(nums1[j+1]+nums2[l],make_pair(j+1,l)));
               s.insert(make_pair(j+1,l));
            }
            
            d=s.find(make_pair(j,l+1));
            
            if(d==s.end() && l<nums2.size()-1){
                minheap.push(make_pair(nums1[j]+nums2[l+1],make_pair(j,l+1)));
                s.insert(make_pair(j,l+1));
            }
            
            i++;
        }
        
        return v;
    }
};