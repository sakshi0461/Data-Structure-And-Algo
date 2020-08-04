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
    void search(trie* t,vector<string>&v,string s){
        
        if(t->child.size()==0){
            v.push_back(s);
            return;
        }
        
        bool p=true;
        for(auto i:t->child){
            
            if(i.second->isend){
               p=false; 
               search(i.second,v,s+i.first);
            }
        }
        
        if(p)
         v.push_back(s);

    }
    string longestWord(vector<string>& words) {
        
        tree=newnode();
        
        for(int i=0;i<words.size();i++)
            insert(words[i]);
        
        vector<string>v;
        search(tree,v,"");
        
        sort(v.begin(),v.end());
        string s1="";
        int maxi=0;
        for(int i=0;i<v.size();i++){
            if(maxi<v[i].length()){
                maxi=v[i].length();
                s1=v[i];
            }
        }
        return s1;
    }
};