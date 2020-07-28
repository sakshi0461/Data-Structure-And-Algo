class Solution {
public:
    bool ispalin(string s){
        int i=0,j=s.length()-1;
        
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    void generate(vector<vector<string>>&v,string s,int start,vector<string>&temp){
        
        if(start>=s.length()){
             v.push_back(temp);
             return;
        }
                 
        for(int i=start;i<s.length();i++){
           string ss=s.substr(start,i-start+1);
            if(ispalin(ss)){
                temp.push_back(ss);
                generate(v,s,i+1,temp);
                temp.pop_back();
            }
        }
        
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        vector<string>temp;
        generate(v,s,0,temp);
        return v;
    }
};