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
    int MAH(vector<int>heights) {
        
        vector<int>left=NSL(heights);
        vector<int>right=NSR(heights);
        
        int maxi=0;
        
        for(int i=0;i<heights.size();i++){
            int d=(right[i]-1-left[i])*heights[i];
            maxi=max(maxi,d);    
        }
        
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
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
            maxi=max(maxi,MAH(v));
        }
        
        return maxi;
    }
};