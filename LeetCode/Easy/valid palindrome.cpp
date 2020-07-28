class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        while(i<j){
            if(!((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')))
                i++;
            else if(!((s[j]>='a' && s[j]<='z')||(s[j]>='0' && s[j]<='9')))
                j--;
            else if(s[i]==s[j]){
                i++;
                j--;
            }
            else
            return false;
        }
        return true;
    }
};