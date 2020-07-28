class Solution {
public:
    bool isValid(string s) {
        
            stack<char>sta;
         int i=0;
            while(i<s.length()){
                    if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                            sta.push(s[i]);
                    else if(s[i]==')'){
                            if(!sta.empty() && sta.top()=='(')
                                    sta.pop();
                            else
                              return false;
                    }
                    else if(s[i]=='}'){
                            if(!sta.empty() && sta.top()=='{')
                                    sta.pop();
                            else
                                    return false;
                    }
                    else if(s[i]==']'){
                            if(!sta.empty() && sta.top()=='[')
                                    sta.pop();
                            else
                                    return false;
                    }
                    else
                           return false;
                    i++;
            }
       return sta.empty()==true;
    }
};