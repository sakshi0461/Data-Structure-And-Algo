class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int maxiii=INT_MAX;
        for(int i=A.size()-2;i>=0;i--){
            for(int j=0;j<A[0].size();j++){
                
                int maxi=A[i+1][j];
                if(j>=1)
                    maxi=min(maxi,A[i+1][j-1]);
                if(j<A[0].size()-1)
                    maxi=min(maxi,A[i+1][j+1]);
                
                A[i][j]+=maxi;
             
            }
        }
        
        for(int i=0;i<A[0].size();i++)
            if(maxiii>A[0][i])
                maxiii=A[0][i];
        
        return maxiii;
    }
};