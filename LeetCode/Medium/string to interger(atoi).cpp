class Solution {
public:
    int myAtoi(string s) {
        
       int i=0;
    int num=0;
        bool p=false;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            if(s[i]=='-'){ p=true; continue;}
            if(s[i]>='0' && s[i]<='9') {
               if(num>INT_MAX/10)
                   if(p) return INT_MIN;
                else return INT_MAX;
                num=num*10+(s[i]-'0');
            }
            else
                break;
        }
        
        if(p)
            num=-1*num;
        return num;
    }
};