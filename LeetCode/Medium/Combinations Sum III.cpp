class Solution {
public:
    void comb(vector<vector<int>>&v,int n,int k,vector<int>temp,int start){
        if((n==0 && temp.size()!=k) || (n!=0 && temp.size()==k)) return;
        if(temp.size()==k && n==0){
            if(find(v.begin(),v.end(),temp)==v.end())
            v.push_back(temp);
            return;
        }
        
        for(int i=start;i<=9;i++){
            if(i>n) continue;
            temp.push_back(i);
            comb(v,n-i,k,temp,i+1);
            temp.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>temp;
        vector<vector<int>>v;
        comb(v,n,k,temp,1);
        return v;
    }
};