class Solution {
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
    string convert(string s){
        
        trie* t=tree;
        
        string s1="";
        for(int i=0;i<s.length();i++){
            char x=s[i];
            
            if(t->child.find(x)==t->child.end())
                break;

            s1+=x;
            if(t->child[x]->isend) {
               t=t->child[x];
                break;
            }
            t=t->child[x];
        }
        
        if(t->isend)
           return s1;
        return s;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        
        tree=newnode();
        
        for(int i=0;i<dict.size();i++)
            insert(dict[i]);
        
        string s1="";
        string s2="";
        for(int i=0;i<sentence.length();i++){
            
            if(sentence[i]==' '){
                s2=s2+convert(s1)+" ";
                s1="";
                continue;
            }
            
            s1+=sentence[i];
        }
        
        if(s1!="")
            s2=s2+convert(s1);
        
        return s2;
    }
};