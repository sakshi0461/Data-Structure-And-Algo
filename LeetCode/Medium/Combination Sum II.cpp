class Solution {
public:
     void comb(vector<vector<int>>&v,vector<int>&sett,int target,vector<int>temp,int start){
        if(target==0){
            sort(temp.begin(),temp.end());
            if(find(v.begin(),v.end(),temp)==v.end())
            v.push_back(temp);
            return;
        }
        
        for(int i=start;i<sett.size();i++){
            if(sett[i]>target) continue;
            temp.push_back(sett[i]);
            comb(v,sett,target-sett[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int>temp;
        vector<vector<int>>v;
        comb(v,candidates,target,temp,0);
        return v;   
    }
};