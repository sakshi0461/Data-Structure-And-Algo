class Solution {
public:
    bool isPalindrome(int x) {
        
        int n1=x,n2=0;
        bool p=false;
        if(x<0)
            return false;
            x=abs(x);
        while(x>0){
            if(n2>INT_MAX/10) return false;
            n2=n2*10+(x%10);
            x=x/10;
        }
        
        if(p)
            n2=n2*-1;
        return n1==n2;
    }
};