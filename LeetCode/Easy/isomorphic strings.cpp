class Solution {
public:
        bool funct(string s,string t){
                unordered_map<char,vector<int>>mp;
            for(int i=0;i<s.length();i++)
                    mp[s[i]].push_back(i);
            
            for(auto i=mp.begin();i!=mp.end();i++){
                    
                    char c=t[i->second[0]];
                    for(int j=1;j<i->second.size();j++)
                            if(t[i->second[j]]!=c)
                                    return false;
            }
            
            return true;
        }
    bool isIsomorphic(string s, string t) {
        
            if(s.length()!=t.length()) return false;
            
            return funct(s,t) && funct(t,s);
    }
};