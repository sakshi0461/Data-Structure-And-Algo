class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        
        if(n==0) return false;
        
        int m=matrix[0].size();
        
        int i=0,j=n*m-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            int row=mid/m;
            int col=mid-(row*m);
            
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                j=mid-1;
            else
                i=mid+1;
            
            cout<<mid<<" ";
        }
        
        return false;
    }
};