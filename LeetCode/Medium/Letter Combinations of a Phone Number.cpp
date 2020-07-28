class Solution {
public:
    void create(vector<string>&v,unordered_map<int,vector<string>>&mp,string s,string digit){
        if(s.size()==digit.size()){
            v.push_back(s);
            return;
        }
        
        
        for(int i=0;i<mp[digit[s.size()]-'0'].size();i++){
            string x=mp[digit[s.size()]-'0'][i];
            create(v,mp,s+x,digit);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int,vector<string>>mp;
        
        mp[2]={"a","b","c"};
        mp[3]={"d","e","f"};
        mp[4]={"g","h","i"};
        mp[5]={"j","k","l"};
        mp[6]={"m","n","o"};
        mp[7]={"p","q","r","s"};
        mp[8]={"t","u","v"};
        mp[9]={"w","x","y","z"};
        
        vector<string>v;
        if(digits.size()==0) return v;
        
        create(v,mp,"",digits);
        
        return v;
    }
};