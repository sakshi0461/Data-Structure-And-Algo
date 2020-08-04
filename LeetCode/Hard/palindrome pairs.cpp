class Solution {
public:
    struct trie{
        bool isend;
        int n;
        unordered_map<char,trie*>child;
    };
    trie* newnode(){
        trie* node=new trie();
        node->isend=false;
        return node;
    }
    trie* tree;
    bool ispalin(string s){
        int i=0,j=s.length()-1;
        
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    void insert(string s,int val){
        trie* t=tree;
        
        for(int i=0;i<s.length();i++){
            char x=s[i];
            
            if(t->child.find(x)==t->child.end())
                t->child[x]=newnode();
            
            t=t->child[x];
        }
        
        t->isend=true;
        t->n=val;
    }
    void find(trie* t,vector<vector<int>>&v,int val,string s){
        
        if(t->isend && t->n!=val){
                if(ispalin(s))
                    v.push_back({t->n,val});
        }
        
        for(auto i=t->child.begin();i!=t->child.end();i++)
            find(i->second,v,val,s+i->first);
        
    }
    void search(string s,vector<vector<int>>&v,int val){
        
        trie* t=tree;
        
        if(t->isend && t->n!=val){
                if(ispalin(s))
                    v.push_back({t->n,val});
        }
        
        int i;
        for(i=0;i<s.length();i++){
            char x=s[i];
            
            if(t->child.find(x)==t->child.end())
                break;
            
            t=t->child[x];
            if(t->isend && t->n!=val){
                if(ispalin(s.substr(i+1,s.length()-i-1))){
                    v.push_back({t->n,val});
                }
            }
        }
        
        if(i==s.length()){
            string so="";
            for(auto j=t->child.begin();j!=t->child.end();j++)
               find(j->second,v,val,so+j->first);
        }
        
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>>v;
        
        tree=newnode();
        
        for(int i=0;i<words.size();i++)
            insert(words[i],i);

        
        for(int i=0;i<words.size();i++){
            string s=words[i];
            reverse(s.begin(),s.end());
           search(s,v,i);
        }
        
        return v;
    }
};