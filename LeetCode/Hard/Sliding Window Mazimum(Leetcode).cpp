class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>>maxheap;
        
        int d=nums.size();
        if(d>k)
            d=k;
        
        for(int l=0;l<d;l++)
            maxheap.push(make_pair(nums[l],l));
        
        vector<int>v;
        v.push_back(maxheap.top().first);
        
        int i=1,j=k;
        
        while(j<nums.size()){
           
            if(maxheap.top().second==i-1)
                maxheap.pop();
            
            while(!maxheap.empty() && maxheap.top().second<i)
                maxheap.pop();
            
            maxheap.push(make_pair(nums[j],j));
            v.push_back(maxheap.top().first);
            
            j++;
            i++;
        }
        
        return v;
    }
};