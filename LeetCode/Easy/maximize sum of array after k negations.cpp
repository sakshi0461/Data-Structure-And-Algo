class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int k) {
        
        sort(A.begin(),A.end());
        int sum=0;
        
        for(int i=A.size()-1;i>=0;i--)
                sum+=A[i];
        
        int c=-1;
        for(int i=0;i<A.size();i++){
            if(A[i]>0 || k<=0){ c=i;break;}
            k--;
            sum+=2*(-1*A[i]);
        }
        
        if(k%2==0) return sum;
        
        if(c==0) return sum-2*(A[0]);
        
        return max(sum+2*(A[c-1]),sum-2*A[c]);
    }
};