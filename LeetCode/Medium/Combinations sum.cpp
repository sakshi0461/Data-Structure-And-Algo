class Solution {
public:
    void comb(vector<vector<int>>&v,vector<int>&sett,int target,vector<int>temp,int start){
        if(target<=-1) return;
        if(target==0){
            if(find(v.begin(),v.end(),temp)==v.end())
            v.push_back(temp);
            return;
        }
        
        for(int i=start;i<sett.size();i++){
            if(sett[i]>target) continue;
            temp.push_back(sett[i]);
            comb(v,sett,target-sett[i],temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>v;
        comb(v,candidates,target,temp,0);
        return v;
    }
};