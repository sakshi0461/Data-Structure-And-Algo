class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x<=3) return 1;
        
        int i=0,j=x/2,mid;
        
        while(i<=j){
            mid=i+(j-i)/2;
            
            if(mid==(x/mid))
                return mid;
            else if(mid>(x/mid))
                j=mid-1;
            else
                i=mid+1;
        }
        
        return j;
    }
};