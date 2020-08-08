class Solution {
public:
    bool ispossible(vector<int>&piles,int k,int h){
        int c=0;
        for(int i=0;i<piles.size();i++)
            c+=ceil((double)piles[i]/(double)k);
        return c<=h;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int n=piles.size();
        
        if(H==n) return *max_element(piles.begin(),piles.end());
        
        long long int sum=0;
        for(int i=0;i<piles.size();i++)
            sum+=piles[i];
        
         int k=ceil((double)sum/(double)H);
        
         if(ispossible(piles,k,H)) return k;
        
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        
        while(i<j){
            int mid=i+(j-i)/2;
            
            if(ispossible(piles,mid,H))
                j=mid;
            else
                i=mid+1;
        }
        
        return j;
    }
};