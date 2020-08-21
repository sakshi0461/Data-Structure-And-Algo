// class compare{
//     bool operator()(vector<int>a,vector<int>b){
//         if(a[0]==b[0])
//             return a[1]<b[1];
//         return a[0]<b[0];
//     }
// };
class Solution {
public:
   static bool compare(vector<int>a,vector<int>b){
          if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>v;
        
        sort(intervals.begin(),intervals.end(),compare);
        
        if(intervals.size()==0) return v;
        
        int start=intervals[0][0];
        int end=intervals[0][1];
        
        bool p=false;
        
        for(int i=1;i<intervals.size();i++){
           if(intervals[i][0]<=end){
               end=max(intervals[i][1],end);
               //p=false;
           }
           else{
               v.push_back({start,end});
               start=intervals[i][0];
               end=intervals[i][1];
               //p=true;
           }
        }
        
        //if(!p)
          v.push_back({start,end});
        
        return v;
    }
};