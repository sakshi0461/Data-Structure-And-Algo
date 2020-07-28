class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1) return 1;
        long long int m=(long long int)n;
        double t=sqrt(1+2*m);
        return (int)((2*t-1)/2);
    }
};