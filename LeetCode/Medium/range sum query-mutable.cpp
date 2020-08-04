class NumArray {
public:
    vector<int>seg;
    int si;
    void builtseg(vector<int>nums,int start,int end,int index){
        
        if(start>end) return;
        if(start==end){
            seg[index]=nums[start];
            return;
        }
        
        int mid=start+(end-start)/2;
        
        builtseg(nums,start,mid,2*index);
        builtseg(nums,mid+1,end,2*index+1);
        
        seg[index]=seg[2*index]+seg[2*index+1];
    }
    NumArray(vector<int>& nums) {
        si=nums.size();
        seg=vector<int>(4*si+1,-1);
        builtseg(nums,0,si-1,1);
    }
    
    void updatee(int qindex,int val,int start,int end,int index){
        
        if(start==end){
            seg[index]=val;
            return;
        }
        
        int mid=start+(end-start)/2;
        
        if(qindex>mid)
            updatee(qindex,val,mid+1,end,2*index+1);
        else
            updatee(qindex,val,start,mid,2*index);
        
        seg[index]=seg[2*index]+seg[2*index+1];
        
    }
    void update(int i, int val) {
        updatee(i+1,val,1,si,1);
    }
    int findsum(int qstart,int qend,int start,int end,int index){
        
        if(qstart>end || qend<start)
            return 0;
        if(start>=qstart && end<=qend)
            return seg[index];
        
        int mid=start+(end-start)/2;
        
    return findsum(qstart,qend,start,mid,2*index)+findsum(qstart,qend,mid+1,end,2*index+1);
    }
    int sumRange(int i, int j) {
        
        return findsum(i+1,j+1,1,si,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */