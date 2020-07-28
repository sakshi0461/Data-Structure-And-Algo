class Solution {
public:
    int maxProfit(vector<int>&prices){
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
//     //METHOD 1 SUMMING OVER EVERY VALLEY AND PEAL
//     int downfall(vector<int>&prices,int i){
//         int n=prices.size();
//         int index=i;
//         for(int j=i+1;j<n;j++){
//             if(prices[i]==prices[j]) continue;
//             if(prices[j]<prices[i]){
//                 index=j;
//                 i=j;
//             }
//             if(prices[j]>prices[i])
//                 return i;
//         }
//         return -1;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int f=downfall(prices,0);
//         int i=f+1,profit=0;
//         if(f==-1) return profit;
//         while(i<n){
//             if(prices[f]<prices[i]){
//                 profit+=prices[i]-prices[f];
//                 f=downfall(prices,i);
//                if(f==-1) return profit;
//                 i=f;
//             }
//             i++;
//         }
        
//         return profit;
//     }
    
};