class Solution {
public:
    void permu(vector<string>&v,int count1,int count2,int n,string s){
        
        if(s.length()==2*n){
            v.push_back(s);
            return;
        }
        
        if(count1<n)
            permu(v,count1+1,count2,n,s+"(");
        if(count2<count1)
            permu(v,count1,count2+1,n,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        permu(v,0,0,n,"");
        return v;
    }
};