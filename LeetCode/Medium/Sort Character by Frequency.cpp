class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        
        priority_queue<pair<int,char>>maxheap;
        
        for(auto j:mp){
            maxheap.push(make_pair(j.second,j.first));
        }
        
        string str="";
        
        while(!maxheap.empty()){
            auto p=maxheap.top();
            maxheap.pop();
            while(p.first--)
                str+=p.second;
        }
        
        return str;
    }
};