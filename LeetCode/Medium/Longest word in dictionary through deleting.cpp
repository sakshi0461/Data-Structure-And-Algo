class Solution {
public:
    bool istrue(string s,string s1){
        
        int i=0,j=0;
        
        while(i<s.length() && j<s1.length()){
            if(s[i]==s1[j]){
                i++;
                j++;
            }
            else
                j++;
        }
            
        return i==s.length();
    }
    string findLongestWord(string s, vector<string>& d) {
        
        sort(d.begin(),d.end());
        string s1="";
        int maxi=0;
        for(int i=0;i<d.size();i++){
            
            if(maxi<d[i].length()){
                if(istrue(d[i],s)){
                    maxi=d[i].length();
                    s1=d[i];
                }
            }
        }
        
        return s1;
    }
};