class Solution {
public:
    vector<int> plusOne(vector<int>& digit) {
        int carry=1;
        for(int i=digit.size()-1;i>=0;i--){
            int t=digit[i]+carry;
            digit[i]=t%10;
            carry=(t-digit[i])/10;
        }
        if(carry!=0)
            digit.insert(digit.begin(),carry);
        return digit;
    }
};