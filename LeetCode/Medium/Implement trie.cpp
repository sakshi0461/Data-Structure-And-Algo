class Trie {
public:
    /** Initialize your data structure here. */
    struct trie{
      bool isend;
      unordered_map<char,trie*>child;
    };
    trie* newnode(){
        trie* node=new trie();
        node->isend=false;
        return node;
    }
    trie* tt;
    Trie() {
        tt=new trie();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie* t=tt;
        for(int i=0;i<word.length();i++){
            char x=word[i];
            
            if((t->child).find(x)==t->child.end())
                t->child[x]=new trie();
            
            t=t->child[x];
        }
        t->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie* t=tt;
        
        for(int i=0;i<word.length();i++){
            char x=word[i];
            
            if(t->child.find(x)==t->child.end())
                return false;
            
            t=t->child[x];
        }
        
        return t && t->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie* t=tt;
         for(int i=0;i<prefix.length();i++){
            char x=prefix[i];
            
            if(t->child.find(x)==t->child.end())
                return false;
            
            t=t->child[x];
        }
        
        return t;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */Implement 