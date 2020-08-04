class Solution {
public:
    struct trie{
        bool isend;
        int val;
        unordered_map<string,trie*>child;
    };
    trie* newnode(){
        trie* node=new trie();
        node->isend=false;
        return node;
    }
    trie* tree;
    void insert(string s,int val){
        trie* t=tree;
            
    if(t->child.find(s)==t->child.end())
        t->child[s]=newnode();
            
        t=t->child[s];
    
        t->isend=true;
        t->val=val;
    }
    bool match(string s,int start,trie* t,int val){
        
        if(start>=s.length())
            return true;
        
        for(int k=1;k<=s.length()-start;k++){
            string str=s.substr(start,k);
            if(t->child.find(str)!=t->child.end()){
                if(t->child[str]->val!=val){
                    if(match(s,start+k,t,val))
                        return true;
                }
            }     
        }
        
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        tree=newnode();
        for(int i=0;i<words.size();i++){
           if(words[i]=="") continue;
            insert(words[i],i);
        }
        
        vector<string>v;
        trie* t=tree;
        for(int i=0;i<words.size();i++){
            if(match(words[i],0,t,i) && words[i]!="")
                v.push_back(words[i]);
        }
        
        return v;
    }
};