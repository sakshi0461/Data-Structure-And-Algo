class Solution {
public:
    pair<string,int> expand(string s,int start,int end){
       
        int count=0;
        if(start==end){ 
            count++;
            start--;
            end++;
        }
        
        while(start>=0 && end<s.length() && s[start]==s[end]){
           count+=2;
            start--;
            end++;
        }
        
        string s1=s.substr(start+1,end-start-1);
        
        return make_pair(s1,count);
    }
    string longestPalindrome(string s) {
        
        int longest=0;
        string s1="";
        for(int i=0;i<s.length();i++){
            pair<string,int> d1=expand(s,i,i);
            pair<string,int> d2=expand(s,i,i+1);
            
            if(d1.second>longest){
                s1=d1.first;
                longest=d1.second;
            }
            if(d2.second>longest){
                s1=d2.first;
                longest=d2.second;
            }
        }
        
        return s1;
    }
    string longestPalindrome(string s) {
        
        int dp[s.length()+1][s.length()+1];
        memset(dp,0,sizeof(dp));
        
        int maxi=0,index;
        
        for(int k=0;k<s.length()+1;k++){
            for(int i=0;i<s.length()+1;i++){
                if(k==0 || i==0)
                    dp[i][k]=0;
                else if(s[i-1]==s[i-1+k] && dp[i+1][k-1]!=0)
                    dp[i][k]=2+dp[i+1][k-1];
                else
                    dp[i][k]=0;
                
                if(maxi<dp[i][k]){
                    maxi=dp[i][k];
                    index=i;
                }
            }
        }
        
        string ss="";
        int i=0;
        
        while(maxi--){
            ss+=s[index+i];
            i++;
        }
        
        return ss;
    }
};