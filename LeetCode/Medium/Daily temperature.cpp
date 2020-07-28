class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        stack<pair<int,int>>s;
        
        vector<int>v(T.size(),0);
        
        for(int i=T.size()-1;i>=0;i--){
            
            while(!s.empty() && s.top().first<=T[i])
                s.pop();
            if(s.empty())
                v[i]=0;
            else
                v[i]=s.top().second-i;
            s.push(make_pair(T[i],i));
        }
              
        return v;
    }
};