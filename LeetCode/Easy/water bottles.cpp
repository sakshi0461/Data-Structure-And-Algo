class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int bhari=numBottles;
        int count=bhari;
        int khali=bhari;
        bhari=0;
        
        while(khali>=numExchange){
            bhari=(khali)/numExchange;
            khali=khali-(bhari*numExchange)+bhari;
            count+=bhari;
        }
        
        return count;
    }
};