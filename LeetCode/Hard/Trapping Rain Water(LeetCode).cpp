class Solution {
public:
    vector<int> NGL(vector<int>v){
        
        vector<int>store;
        int maxi=-1;
        
        for(int i=0;i<v.size();i++){
            if(maxi<v[i])
                store.push_back(-1);
            else
                store.push_back(maxi);
            maxi=max(maxi,v[i]);
        }
        
        return store;
    }
    vector<int> NGR(vector<int>v){
        vector<int>store;
        
        int maxi=-1;
        for(int i=v.size()-1;i>=0;i--){
                if(maxi<v[i])
                    store.push_back(-1);
                else
                    store.push_back(maxi);
            maxi=max(maxi,v[i]);
        }
        
        reverse(store.begin(),store.end());
        
        return store;
    }
    int trap(vector<int>& height) {
        int rain=0;
        
        vector<int>ngl=NGL(height);
        vector<int>ngr=NGR(height);
        
        for(int i=0;i<height.size();i++){
           int d=min(ngl[i],ngr[i])-height[i];
            if(d<0) continue;
            rain+=d;
        }
        
        return rain;
    }
};