class Solution {
public:
    void permute(string s,vector<string>&v,string temp,int index){
        
        if(index==s.length()){
            v.push_back(temp);
            return;
        }
        
          permute(s,v,temp+s[index],index+1);
         
            if(s[index]>='a' && s[index]<='z')
                permute(s,v,temp + (char)(s[index]-'a'+'A'),index+1);
            else if(s[index]>='A' && s[index]<='z')
                permute(s,v,temp + (char)(s[index]-'A'+'a'),index+1);

    }
    vector<string> letterCasePermutation(string S) {
        
        vector<string>v;
        permute(S,v,"",0);
        return v;
    }
};