class StreamChecker {
public:
    struct trie{
        bool isend;
        unordered_map<char,trie*>child;
    };
    trie* newnode(){
        trie* node=new trie();
        node->isend=false;
        return node;
    }
    trie* tree;
    vector<char>v;
    void insert(string s){
        trie* t=tree;
        
        for(int i=0;i<s.length();i++){
            char x=s[i];
            
            if(t->child.find(x)==t->child.end())
                t->child[x]=newnode();
            
            t=t->child[x];
        }
        t->isend=true;
    }
    StreamChecker(vector<string>& words) {
        tree=newnode();
        
        for(int i=0;i<words.size();i++){
            string s=words[i];
            reverse(s.begin(),s.end());
            insert(s);
        }
    }
    bool find(){
        
        trie* t=tree;
        
        for(int i=v.size()-1;i>=0;i--){
            char x=v[i];
           if(t->child.find(x)==t->child.end())
               return false;
            
           t=t->child[x];
            if(t->isend)
                return true;
        }
        
        return t->isend==true;
    }
    bool query(char letter) {
        
        v.push_back(letter);
        
        return find();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */