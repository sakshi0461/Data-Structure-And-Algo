class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mp;
        
        for(int i=0;i<strs.size();i++){
            string s1=strs[i];
            sort(s1.begin(),s1.end());
                mp[s1].push_back(strs[i]);
        }
        
        vector<vector<string>>v;
        
        for(auto i=mp.begin();i!=mp.end();i++)
            v.push_back(i->second);
        
        return v;
    }
};