class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int count=0;
        for(int i=1;i<points.size();i++){
            if(points[i-1][0]==points[i][0]){
                count+=abs(points[i][1]-points[i-1][1]);
            }
            else if(points[i][1]==points[i-1][1]){
                count+=abs(points[i][0]-points[i-1][0]);
            }
            else if(abs(points[i][1]-points[i-1][1])==abs(points[i][0]-points[i-1][0]))
                count+=abs(points[i][1]-points[i-1][1]);
            else{
             int d=min(abs(points[i][1]-points[i-1][1]),abs(points[i][0]-points[i-1][0]));
              if(d==abs(points[i][0]-points[i-1][0]))
                count+=d+min(abs(points[i][1]-(points[i-1][1]+d)),abs(points[i][1]-(points[i-1][1]-d)));
              else
                count+=d+min(abs(points[i][0]-(points[i-1][0]+d)),abs(points[i][0]-(points[i-1][0]-d)));
            }
        }
        
        return count;
    }
};