class Solution {
public:
    //UNION-FIND
    int maxi=1;
    int findparent(unordered_map<int,int>&parent,int x){
        if(parent[x]==INT_MIN)
            return x;
        return findparent(parent,parent[x]);
    }
void unions(int x,int y,unordered_map<int,int>&parent,unordered_map<int,int>&size){
        if(parent.find(x)==parent.end() || parent.find(y)==parent.end()) return;
    
        x=findparent(parent,x);
        y=findparent(parent,y);
        
        if(x==y) return;
        
        if(size[x]>size[y]){
            parent[y]=x;
            size[x]+=size[y];
            maxi=max(maxi,size[x]);
        }
        else{
            parent[x]=y;
            size[y]+=size[x];
            maxi=max(maxi,size[y]);
        }
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_map<int,int>parent(n);
        unordered_map<int,int>size(n);
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++){
         parent[nums[i]]=INT_MIN;
         size[nums[i]]=1;
        }
        
        for(int i=0;i<n;i++){
            int e=nums[i];
            int ahead=e+1;
            int behead=e-1;
            
            unions(ahead,e,parent,size);
            unions(behead,e,parent,size);
        }
        
        
        return maxi;
    }
};