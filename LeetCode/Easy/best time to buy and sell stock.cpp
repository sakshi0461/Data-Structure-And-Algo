class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini[prices.size()],maxi[prices.size()];
        
        int minii=INT_MAX,maxii=INT_MIN,profit=0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minii)
                minii=prices[i];
            mini[i]=minii;
        }
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>maxii)
                maxii=prices[i];
            maxi[i]=maxii;
            if(profit<maxi[i]-mini[i])
                profit=maxi[i]-mini[i];
        }
        return profit;
    }
};