class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        
        for(int i=1;;i++){
            count+=(n/pow(5,i));
            if(n/pow(5,i)==0)
                break;
        }
        
        return count;
    }
};