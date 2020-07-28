class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==0 || num==1) return true;
        if(num<=3) return false;
        
        int i=0,j=num/2;
        double mid;
        double n=(double)num;
        while(i<=j){
            mid=(double)(i+(j-i)/2);
            
            if(mid==(n/mid))
                return true;
            else if(mid>(n/mid))
                j=mid-1;
            else
                i=mid+1;
        }
        
        return false;
    }
};