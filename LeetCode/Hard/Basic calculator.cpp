class Solution {
public:
     string convert(string s){
         
        long long int i=0,n1=0;
        
        if(s[i]=='(' || s[i]==')' || s[i]==' ') i++;
        
        while(i<s.length() && s[i]>='0' && s[i]<='9'){
            if(s[i]==' ' || s[i]=='(' || s[i]==')')break;
            n1=n1*10+(s[i]-'0');
            i++;
        }
         
        long long int n2=0;
        
        while(i<s.length()){
            if(s[i]==' ' || s[i]=='(' || s[i]==')'){i++; continue;}
            if(s[i]=='+' || s[i]=='-'){
                char x=s[i];
                i++;
                if(s[i]==' ' || s[i]=='(' || s[i]==')') i++;
                
                while(i<s.length() && s[i]!='+' && s[i]!='-'){
                     if(s[i]==' ' || s[i]=='(' || s[i]==')')break;
                    n2=n2*10+(s[i]-'0');
                    i++;
                }
                if(x=='+')
                    n1=n1+n2;
                else
                    n1=n1-n2;
        
                n2=0;
            }
        }
      
        return to_string(n1);
    }
    string solve(string s){
        string s1="";
        
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            if(s[i]=='('){
                stack<int>sta;
                sta.push('(');
                i++;
                string ss="";
                while(!sta.empty()){
                    if(s[i]==' '){i++; continue;}
                    if(s[i]=='(')
                        sta.push('(');
                    else if(s[i]==')')
                        sta.pop();
                    if(!sta.empty()){
                       ss+=s[i];
                       i++;
                    }
                }
                string sss=solve(ss);
                if(sss[0]=='-' && s1.length()!=0){
                     if(s1[s1.length()-1]=='+'){
                        s1[s1.length()-1]='-';
                        s1+=sss.substr(1,sss.length()-1);
                        }
                    else{
                        s1[s1.length()-1]='+';
                        s1+=sss.substr(1,sss.length()-1);
                    }
                }
                else
                    s1+=sss;
            }
            else
                s1+=s[i];
        }
        
        return convert(s1);
    }
    int calculate(string s) {
        
        int n=stoi(solve(s));
        
        return n;
    }
};