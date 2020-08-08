class Solution {
public:
    string open(string s,int k){
        
        string str="";
        
        int t=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9')
                t=t*10+(s[i]-'0');
            else if(s[i]=='['){
                stack<char>sta;
                sta.push('[');
                string s1="";
                while(!sta.empty()){
                    i++;
                    if(s[i]=='[')
                        sta.push('[');
                    if(s[i]==']')
                        sta.pop();
                    if(!sta.empty())
                        s1+=s[i];
                }
                
                s1=open(s1,t);
                str+=s1;
                t=0;
            }
            else
                str+=s[i];
        }
        
        string ss="";
        
        while(k--)
            ss+=str;
        
        return ss;
    }
    string decodeString(string s) {
        
        string str="";
        
        str=open(s,1);
        
        return str;
    }
};