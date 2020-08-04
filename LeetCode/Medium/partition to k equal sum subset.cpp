class Solution {
public:
bool isparti(vector<int>&subset,vector<bool>&visited,vector<int>&nums,int k,int in,int sum){
       
        if(subset[in]==sum){
            in--;
            
            if(in==-1)
                return true;
            
            return isparti(subset,visited,nums,k-1,in,sum);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
          if(visited[i]) continue;
            
            if(subset[in]+nums[i]<=sum){
                subset[in]+=nums[i];
                visited[i]=true;
                if(isparti(subset,visited,nums,k,in,sum))
                    return true;
                visited[i]=false;
                subset[in]-=nums[i];
            }
        }
        
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(k==1)
            return true;
        
        if(n<k)
            return false;
        
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum%k!=0)
            return false;
        
        sort(nums.begin(),nums.end());
        
        sum=sum/k;
        int row=n-1;
        while(row>=0 && nums[row]==sum){
            row--;
            k--;
        }
        
        if(nums[n-1]>sum) return false;
        
        vector<int>subset(k,0);
        vector<bool>visited(n,false);
        
        return isparti(subset,visited,nums,k,k-1,sum);
    }
};