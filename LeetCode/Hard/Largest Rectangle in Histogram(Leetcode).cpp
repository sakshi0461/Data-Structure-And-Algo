class Solution {
public:
    vector<int> NSL(vector<int>height){
        
        vector<int>v;
        
        stack<pair<int,int>>s;
        
        for(int i=0;i<height.size();i++){
            
            while(!s.empty() && s.top().first>=height[i])
                s.pop();
            
            if(s.empty())
                v.push_back(-1);
            else
                v.push_back(s.top().second);
            
            s.push(make_pair(height[i],i));
        }
        
        return v;
    }
    vector<int> NSR(vector<int>height){
        
        vector<int>v;
        stack<pair<int,int>>s;
        
        for(int i=height.size()-1;i>=0;i--){
            
            while(!s.empty() && s.top().first>=height[i])
                s.pop();
            
            if(s.empty())
                v.push_back(height.size());
            else
                v.push_back(s.top().second);
            
            s.push(make_pair(height[i],i));
        }
        
        reverse(v.begin(),v.end());
        
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>left=NSL(heights);
        vector<int>right=NSR(heights);
        
        int maxi=0;
        
        for(int i=0;i<heights.size();i++){
            cout<<left[i]<<" "<<right[i]<<"   ";
            int d=(right[i]-1-left[i])*heights[i];
            maxi=max(maxi,d);    
        }
        
        return maxi;
    }
};