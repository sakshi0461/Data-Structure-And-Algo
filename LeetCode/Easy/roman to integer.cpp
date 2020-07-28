class Solution {
public:
    int romanToInt(string s) {
        
        int n=0;
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='I'){
              if(i!=s.length()-1 && (s[i+1]=='V' || s[i+1]=='X'))
                  n--;
              else
                  n++;
            }
            if(s[i]=='V')
                n+=5;
            if(s[i]=='X'){
              if(i!=s.length()-1 && (s[i+1]=='L' || s[i+1]=='C'))
                  n-=10;
              else
                  n+=10;
            }
            if(s[i]=='L')
                n+=50;
            if(s[i]=='C'){
                if(i!=s.length()-1 && (s[i+1]=='D' || s[i+1]=='M'))
                    n-=100;
                else
                    n+=100;
            }
            if(s[i]=='D')
                n+=500;
            if(s[i]=='M')
                n+=1000;
        }
        
        return n;
    }
};