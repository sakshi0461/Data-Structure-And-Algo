class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
       
       unordered_map<int,int>mp;
        
        for(auto i:C)
            for(auto j:D)
                mp[i+j]++;
        
        int count=0;
        
        for(auto i:A)
            for(auto j:B)
                count+=mp[-i-j];
        
        return count;
    }
};