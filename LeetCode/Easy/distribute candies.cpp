class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<candies.size();i++)
            mp[candies[i]]++;
        
        int si=mp.size();
        int n=candies.size();
        
        if(si>=n/2)
            return n/2;
        return si;
    }
};