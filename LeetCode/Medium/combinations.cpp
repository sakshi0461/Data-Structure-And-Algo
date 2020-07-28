class Solution {
public:
    void comb(vector<vector<int>>&v,int n,int k,vector<int>temp,int start){
        if(temp.size()==k){
            v.push_back(temp);
            return;
        }
        
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            comb(v,n,k,temp,i+1);
            temp.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>v;
        comb(v,n,k,temp,1);
        return v;
    }
};