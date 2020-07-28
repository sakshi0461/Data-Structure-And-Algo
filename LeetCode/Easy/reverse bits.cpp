class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num=0;
        int i=32;
        while(i--){
             num=num<<1;
            num+=(n&1);
            n=n>>1;
        }
        
        return num;
    }
};