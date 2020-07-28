class Solution {
public:
    vector<vector<int>> generate(int n) {
        
            vector<vector<int>>v;
            if(n==0) return v;
            v.push_back({1});
            if(n==1) return v;
            v.push_back({1,1});
            if(n==2) return v;
            
            for(int i=2;i<n;i++){
                vector<int>temp(i+1,1);
                for(int j=1;j<i;j++)
                  temp[j]=v[i-1][j]+v[i-1][j-1];
                v.push_back(temp);
            }
            
            return v;
    }
};