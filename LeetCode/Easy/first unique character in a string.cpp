class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end())
                mp[s[i]]=0;
            mp[s[i]]++;
        }
        
        for(int i=0;i<s.length();i++){
              if(mp[s[i]]==1) return i;
        }
        
        return -1;
    }
};