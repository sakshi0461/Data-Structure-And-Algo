class Solution {
public:
    struct compare{
  bool operator()(const pair<int,string>&a,const pair<int,string>&b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
  }  
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>minheap;
        
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++)
            mp[words[i]]++;
        
        for(auto i:mp){
            minheap.push(make_pair(i.second,i.first));
            if(minheap.size()>k)
                minheap.pop();
        }
        
        vector<string>v;
        
        while(!minheap.empty()){
            v.push_back(minheap.top().second);
            minheap.pop();
        }
        
        reverse(v.begin(),v.end());
        
        return v;
    }
};