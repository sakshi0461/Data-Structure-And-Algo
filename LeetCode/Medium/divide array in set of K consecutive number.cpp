class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        if(nums.size()%k!=0) return false;
        
        map<int,int>mp;

for(int i=0;i<nums.size();i++)
   mp[nums[i]]++;

while(!mp.empty()){
  int first=mp.begin()->first;
  int t=k;
   while(t--){
     mp[first]--;
     if(mp[first]==0)
      mp.erase(first);
       first++;
    if((mp.empty() || mp[first]==0)&& t!=0){
        cout<<t<<" ";
        return false;
    }
  }
}

return true;

        
    }
};