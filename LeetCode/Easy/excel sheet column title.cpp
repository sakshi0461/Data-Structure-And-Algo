class Solution {
public:
    string convertToTitle(int n) {
        string s="";
        while(n>0){
            if(n%26==0){
                s+='Z';
                n=(n-26)/26;
            }
            else{
                s+='A'+(n%26)-1;
            n=(n-(n%26))/26;
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};