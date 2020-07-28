class Solution {
public:
    vector<int> NSL(vector<int>v){
        
        vector<int>store;
        stack<pair<int,int>>s;
        
        for(int i=0;i<v.size();i++){
            
            while(!s.empty() && s.top().first>=v[i])
                s.pop();
            
            if(s.empty())
                store.push_back(-1);
            else
                store.push_back(s.top().second);
           
            s.push(make_pair(v[i],i));
        }
        
        return store;
    }
    vector<int> NSR(vector<int>v){
        vector<int>store;
        stack<pair<int,int>>s;
        
        for(int i=v.size()-1;i>=0;i--){
            
            while(!s.empty() && s.top().first>=v[i])
                s.pop();
            
            if(s.empty())
                store.push_back(v.size());
            else
                store.push_back(s.top().second);
            
            s.push(make_pair(v[i],i));
        }
        
        reverse(store.begin(),store.end());
        return store;
    }
    int funct(vector<int>v){
        
        vector<int>left=NSL(v);
        vector<int>right=NSR(v);
        
        int maxi=0;
        
        for(int i=0;i<v.size();i++){
            int d=right[i]-left[i]-1;
            if(d>=v[i] && maxi<v[i]*v[i])
               maxi=v[i]*v[i];
        }
        
        return maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0;
        vector<int>v(matrix[0].size(),0);
        int maxi=0;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1')
                    v[j]++;
                else
                    v[j]=0;
            }
            
            int d=funct(v);
            maxi=max(maxi,d);
        }
        
        return maxi;
    }
};