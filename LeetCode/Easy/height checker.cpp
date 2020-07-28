class Solution {
public:
    int heightChecker(vector<int>& heights) {
            vector<int>num=heights;
            sort(heights.begin(),heights.end());
            int count=0;
            for(int i=0;i<num.size();i++){
                    if(num[i]!=heights[i])
                            count++;
            }
            
            return count;
    }
};