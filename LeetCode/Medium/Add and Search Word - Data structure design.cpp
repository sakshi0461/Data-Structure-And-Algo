class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Trie{
        bool isend;
        unordered_map<char,Trie*>child;
    };
    Trie* newnode(){
        Trie* t=new Trie();
        t->isend=false;
        return t;
    }
    Trie* t;
    WordDictionary() {
        t=new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        Trie* tree=t;
        
        for(int i=0;i<word.length();i++){
           char x=word[i];
            
            if(tree->child.find(x)==tree->child.end())
                tree->child[x]=new Trie();
            
            tree=tree->child[x];
        }
        
        tree->isend=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchh(Trie* tree,string word){
        
        for(int i=0;i<word.length();i++){
            
            char x=word[i];
            if(x=='.'){
                for(auto j:tree->child)
                    if(searchh(j.second,word.substr(i+1,word.length()-i)))
                        return true;
                return false;
            } 
                
            if(tree->child.find(x)==tree->child.end())
                return false;
            tree=tree->child[x];
        }
        
        return tree!=NULL && tree->isend==true;
    }
    bool search(string word) {
        Trie* tree=t;
        return searchh(tree,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */