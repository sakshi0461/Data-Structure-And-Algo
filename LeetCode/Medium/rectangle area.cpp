class Solution {
public:
    bool overlaps(int A,int B,int C,int D,int E,int F,int G,int H){
        return min(D,H)>max(B,F) && min(C,G)>max(A,E);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int a1=abs(D-B)*abs(C-A),a2=0,a3=0;
        
        if(overlaps(A,B,C,D,E,F,G,H))
            a2=(abs(min(D,H)-max(B,F))*abs(min(C,G)-max(A,E)));
            
        a3=abs(H-F)*abs(G-E);
        
        return a1-a2+a3;
    }
};