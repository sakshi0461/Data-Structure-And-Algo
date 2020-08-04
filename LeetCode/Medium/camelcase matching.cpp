class Solution {
public:
    bool funct(string s1,string s2){
        
        int i=0,j=0;
        
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
               if(s1[i]>='A' && s1[i]<='Z')
                   return false;
                i++;
            }
        }
        
        while(i<s1.length()){
            if(s1[i]>='A' && s1[i]<='Z')
                return false;
            i++;
        }
        
        return j==s2.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool>v;
        
        for(int i=0;i<queries.size();i++)
            v.push_back(funct(queries[i],pattern));
        
        
        return v;
    }
};