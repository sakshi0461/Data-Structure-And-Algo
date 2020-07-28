class Solution {
public:
    bool binary(double t,int c){
        int tt=(int)t;
        if((double)tt==t && tt<c)
             return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        
        if(c<=2) return true;
        
        for(int i=2;i<=c/i;i++){
            if(binary(sqrt(c-i*i),c))
                return true;
        }
        return false;
    }
};