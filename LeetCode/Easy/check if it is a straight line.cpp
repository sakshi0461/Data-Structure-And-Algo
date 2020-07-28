class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordi) {
      double slope=((double)coordi[0][1]-(double)coordi[1][1]);
      double cons=((double)coordi[0][1]*(((double)coordi[0][0]-(double)coordi[1][0])))-(slope*(double)coordi[0][0]);
        
        for(int i=1;i<coordi.size();i++){
            double j=((double)coordi[i][1]*((double)coordi[0][0]-(double)coordi[1][0]))-(slope*((double)coordi[i][0]));
            if(j!=cons)
                return false;
        }
        
        return true;
    }
};