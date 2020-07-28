class Solution {
public:
    int reverse(int x) {
        bool p=false;
        if(x<0)
            p=true;
        x=abs(x);
        int num=0;
        
        while(x>0){
            if(num>INT_MAX/10) return 0;
            num=num*10+(x%10);
            x=x/10;
        }
        
        if(p)
            num=-1*num;
        return num;
    }
};