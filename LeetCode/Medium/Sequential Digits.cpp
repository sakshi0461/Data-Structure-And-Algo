class Solution {
public:
    void comb(int low,int high,vector<int>&v,int num){
        
        if(num>high)
            return;
        if(num>=low && num<=high){
            v.push_back(num);
        }
        
        if(num==0){
            for(int i=1;i<=9;i++)
                comb(low,high,v,i);
        }
        else{
            if((num%10+1)%10<=1) return;
            int i=num%10+1;
            comb(low,high,v,num*10+i);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>v;
        comb(low,high,v,0);
        sort(v.begin(),v.end());
        return v;
    }
};