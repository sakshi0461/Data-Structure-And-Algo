class NumArray {
public:
    vector<int>v;
    NumArray(vector<int>& nums) {
        if(nums.size()!=0){
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            v.push_back(v[i-1]+nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if(v.size()==0) return 0;
        if(i==0) return v[j];
        
        return v[j]-v[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */