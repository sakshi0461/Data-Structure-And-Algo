class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        bool dp1[A.size()];
        bool dp2[A.size()];
        memset(dp1,false,sizeof(dp1));
        memset(dp2,false,sizeof(dp2));
        
        dp1[0]=true;
        dp2[A.size()-1]=true;
        
        for(int i=1;i<A.size();i++)
          dp1[i]=dp1[i-1]&(A[i]>A[i-1]);    
        
        for(int i=A.size()-2;i>=0;i--){
            dp2[i]=dp2[i+1]&(A[i]>A[i+1]);
           if(dp1[i] && dp2[i])
               return i;
        }
        
        return -1;
    }
};