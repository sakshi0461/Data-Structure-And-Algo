class Solution {
public:
    int numTrees(int n) {
       long long int res=1;
        for(int i=1;i<n;i++){
            res*=(n+1+i);
            res/=(i);
        }
        res/=n;
        return (int)res;
    }
};