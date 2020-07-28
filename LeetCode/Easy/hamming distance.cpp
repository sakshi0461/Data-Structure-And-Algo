class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorr=x^y;
        return __builtin_popcount(xorr);
    }
};