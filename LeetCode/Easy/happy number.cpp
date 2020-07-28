class Solution {
public:
    bool find(string s,int n){
        int num=0;
        for(int i=0;i<s.length();i++)
            num+=(s[i]-'0')*(s[i]-'0');
      
        if(num==1) return true;
        if(num==n || num<=6) return false;
        
        return find(to_string(num),n);
        
    }
    bool isHappy(int n) {
        string s=to_string(n);
         return find(s,n);
    }
};