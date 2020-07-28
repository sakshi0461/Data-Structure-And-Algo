#define ppi pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<ppi>minheap;
        
        for(int i=0;i<points.size();i++){
            int d=(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            minheap.push(make_pair(d,make_pair(points[i][0],points[i][1])));
            if(minheap.size()>K)
                minheap.pop();
        }
        
        vector<vector<int>>v;
        
        while(!minheap.empty()){
            v.push_back({minheap.top().second.first,minheap.top().second.second});
            minheap.pop();
        }
        
        return v;
    }
};