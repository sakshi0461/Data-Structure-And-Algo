class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        
        int i=0;
        
        vector<vector<int>>v;
        
        while(i<s.length()){
            char x=s[i];
            int x1=i;
            while(i<s.length() && s[i]==x)
                i++;
            int x2=i;
            if(x2-x1>=3)
                v.push_back({x1,x2-1});
        }
        
        return v;
    }
};