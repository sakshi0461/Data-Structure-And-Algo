class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int len=1,maxi=1;
        int start=0,end=0;
        for(int i=1;i<s.length();i++){
            char x=s[i];
            
            for(int j=start;j<=end;j++){
                if(s[j]==x){
                    start=j+1;
                }
            }
            
            if(s[start]==s[i])
                start=i;
            end=i;
            len=end-start+1;
           // cout<<len<<" ";
            maxi=max(maxi,len);
        }
        
        return maxi;
    }
};