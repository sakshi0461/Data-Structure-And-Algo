class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int petrol=0,start=0,tanker=0;
        
        for(int i=0;i<gas.size();i++){
            petrol+=gas[i]-cost[i];
            if(petrol<0){
                start=i+1;
                tanker+=petrol;
                petrol=0;
            }
        }
        
        if(petrol+tanker>=0 && start<gas.size())
            return start;
        return -1;
    }
};