class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i=0,j=0;
        while(i<A.size() && A[i]<0)
            i++;
        j=i-1;
        vector<int>v;
        while(j>=0 && i<A.size()){
            if(A[i]*A[i]<A[j]*A[j]){
                v.push_back(A[i]*A[i]);
                i++;
            }
            else{
                v.push_back(A[j]*A[j]);
                j--;
            }
        }
        while(j>=0){
            v.push_back(A[j]*A[j]);
            j--;
        }
        while(i<A.size()){
            v.push_back(A[i]*A[i]);
            i++;
        }
        return v;
    }
};