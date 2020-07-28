class MagicDictionary {
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
    Trie* tree;
    MagicDictionary() {
        tree=newnode();
    }
    
    /** Build a dictionary through a list of words */
    void insert(string word){
        Trie* t=tree;
        
        for(int i=0;i<word.length();i++){
            char x=word[i];
            
            if(t->child.find(x)==t->child.end())
                t->child[x]=newnode();
            
            t=t->child[x];
        }
        
        t->isend=true;
    }
    void buildDict(vector<string> dict) {
        for(int i=0;i<dict.size();i++)
            insert(dict[i]);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool find(string word){
        
        Trie* t=tree;
        
        for(int i=0;i<word.length();i++){
            char x=word[i];
            
            if(t->child.find(x)==t->child.end())
                return false;
            
            t=t->child[x];
        }
        
        return (t!=NULL) && (t->isend==true);
    }
    bool search(string word) {
        
        for(int i=0;i<word.length();i++){
           char x=word[i];
            for(int j=0;j<26;j++){
                if(j==x-'a') continue;
               word[i]='a'+j;
               if(find(word))
                   return true;
            }
            word[i]=x;
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */