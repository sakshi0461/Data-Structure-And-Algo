class Solution {
public:
    void generate(int n,vector<int>&v,int &num){
        
        if(n==0){
            v.push_back(num);
            return;
        }
        
        generate(n-1,v,num);
        num=num^(1<<(n-1));
        generate(n-1,v,num);
    }
    vector<int> grayCode(int n) {
        
        vector<int>v;
        int num=0;
        generate(n,v,num);
        return v;
    }
};