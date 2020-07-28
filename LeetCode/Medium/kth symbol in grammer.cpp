class Solution {
public:
    int kthGrammar(int N, int k) {
        if(N==1 && k==1) return 0;
        
        if(k%2==0)
            return 1-kthGrammar(N-1,k/2);
        
        return kthGrammar(N-1,(k+1)/2);
    }
};