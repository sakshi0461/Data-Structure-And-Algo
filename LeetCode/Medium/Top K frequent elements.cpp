class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
         if(mp.find(nums[i])==mp.end())
             mp[nums[i]]=0;
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(auto i=mp.begin();i!=mp.end();i++){
            minheap.push(make_pair(i->second,i->first));
            if(minheap.size()>k)
                minheap.pop();
        }
        
        vector<int>v;
        
        while(!minheap.empty()){
            v.push_back(minheap.top().second);
            minheap.pop();
        }
        
        return v;
    }
};