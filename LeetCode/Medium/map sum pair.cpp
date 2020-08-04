class MapSum {
public:
    /** Initialize your data structure here. */
    struct trie{
        int end;
        unordered_map<char,trie*>child;
    };
    trie* newnode(){
        trie* node=new trie();
        node->end=0;
        return node;
    }
    trie* tree;
    MapSum() {
        tree=newnode();
    }
    
    void insert(string key, int val) {
        
        trie* t=tree;
        
        for(int i=0;i<key.length();i++){
           char x=key[i];
            
            if(t->child.find(x)==t->child.end())
                t->child[x]=newnode();
            
            t=t->child[x];
        }
        
        t->end=val;
    }
    
    int funct(trie* t){
        
        int sum=t->end;
        
        for(auto i:t->child){
            sum+=funct(i.second);
        }
        
        return sum;
    }
    int sum(string prefix) {
        
        trie* t=tree;
        
        int sum=0;
        for(int i=0;i<prefix.length();i++){
            char x=prefix[i];
            
            if(t->child.find(x)==t->child.end())
                return 0;
            t=t->child[x];
        }
        
        return funct(t);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */