class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if((s[i]!='a' && s[i]!='A') && (s[i]!='e' && s[i]!='E') && (s[i]!='i' && s[i]!='I') && (s[i]!='o' && s[i]!='O') && (s[i]!='u' && s[i]!='U'))
                i++;
            else if((s[j]!='a' && s[j]!='A') && (s[j]!='e' && s[j]!='E') && (s[j]!='i' && s[j]!='I') && (s[j]!='o' && s[j]!='O') && (s[j]!='u' && s[j]!='U'))
                j--;
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};