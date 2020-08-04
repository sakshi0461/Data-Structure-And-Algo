class Solution {
public:
    struct trie{
        unordered_map<int,trie*>child;
    };
    trie* newnode(){
        trie* node=new trie();
        return node;
    }
    trie* tree;
    void insert(int n){
        trie* t=tree;
        
        int i=31;
        while(i--){
            int x=(n>>i)&1;
            
            if(t->child.find(x)==t->child.end())
                t->child[x]=newnode();
            
            t=t->child[x];
        }
        
    }
    int searchmaxi(int n){
        
        trie* t=tree;
        
       int maxi=0,i=31;
        
        while(i--){
           int num=(n>>i)&1;

             if(t->child.find(1-num)!=t->child.end())
                 num=1-num;
            
           maxi=maxi | ((num^((n>>i)&1))<<i);
            
            t=t->child[num];
        }
        
        return maxi;
    }
    int findMaximumXOR(vector<int>& nums) {
        
        tree=newnode();
        
        for(int i=0;i<nums.size();i++)
           insert(nums[i]);
        
        int maxi=0;
        
        for(int i=0;i<nums.size();i++)
            maxi=max(maxi,searchmaxi(nums[i]));
        
        return maxi;
    }
};