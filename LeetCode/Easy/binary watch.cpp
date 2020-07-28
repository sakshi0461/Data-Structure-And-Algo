class Solution {
public:
    vector<int> hour(int n){
        if(n==0)
         return {0};
        if(n==1)
         return {1,2,4,8};
        if(n==2)
         return {3,5,9,6,10};
         return {7,11};
    }
    vector<int> min(int n){
        if(n==0)
            return {0};
        if(n==1)
            return {1,2,4,8,16,32};
        if(n==2)
            return {3,5,9,17,33,6,10,18,34,12,20,36,24,40,48};
        if(n==3)
            return {7,11,13,14,19,21,22,25,26,28,35,37,38,41,42,44,49,50,52,56};
        if(n==4)
            return {15,23,27,29,30,39,43,45,46,51,53,54,57,58};
        return {31,47,55,59};
    }
    vector<string> readBinaryWatch(int num) {
        
        vector<string>v;
        int mini=3;
        if(num<3)
            mini=num;
        
        for(int i=0;i<=mini;i++){
            vector<int>v1=hour(i);
            if(num-i>5) continue;
            vector<int>v2=min(num-i);
            for(int j=0;j<v1.size();j++){
                for(int k=0;k<v2.size();k++){
                    string s="";
                    if(v1[j]==10 || v1[j]==11){
                        s+=(v1[j]/10+'0');
                        s+=(v1[j]%10+'0');
                    }
                    else
                        s+=v1[j]+'0';
                    s+=':';
                    if(v2[k]>=10){
                        s+=(v2[k]/10+'0');
                        s+=(v2[k]%10+'0');
                    }else{
                        s+='0';
                        s+=(v2[k]+'0');
                    }
                    v.push_back(s);
                }
            }
        }
        
        return v;
    }
};