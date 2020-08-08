class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        if(n==0) return false;
        int m=matrix[0].size();
        
        int i=0,j=m-1;
        
        while(j>=0 && i>=0 && j<m && i<n){
            
            if(target==matrix[i][j])
                return true;
            if(target>matrix[i][j])
                i++;
            else
                j--;
        }
        
        return false;
    }
};