class Solution {
public:
    bool compare(vector<int>a,vector<int>b){
        if(a[0]==b[0])
            return a[1]>=b[1];
        return a[0]>b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& inter) {
       
       sort(inter.begin(),inter.end());
        
       vector<vector<int>>v;
        int i=0;
        while(i<inter.size()){
            
            int first,second;
            first=inter[i][0];
            second=inter[i][1];
            int j=i+1;
            while(j<inter.size()){
                if(inter[j][0]>=first && inter[j][1]<=second)
                    j++;
                else if(inter[j][0]==first && inter[j][1]>second){
                    second=inter[j][1];
                    j++;
                }
                else
                    break;
            }
            
            v.push_back({first,second});
            i=j;
        }
        
        return v.size();
    }
};