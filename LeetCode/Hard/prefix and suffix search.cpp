class WordFilter {
public:
    struct trie{
        unordered_map<string,trie*>child;
        int val;
    };
    trie* newnode(){
        trie* node=new trie();
        return node;
    }
    trie* tree;
    void insert(string s,int val){
        
        trie* t=tree;
            
            if(t->child.find(s)==t->child.end())
                t->child[s]=newnode();
            
             t=t->child[s];
    
        t->val=val;
    }
    WordFilter(vector<string>& words) {
        
        tree=newnode();
        
        for(int i=0;i<words.size();i++){
            string s=words[i];
            reverse(s.begin(),s.end());
            for(int j=0;j<s.length()+1;j++){
                string str=s.substr(0,j);
                for(int k=0;k<s.length()+1;k++){
                    string str2=words[i].substr(0,k);
                    insert(str+"#"+str2,i);
                }
            }
        }
        
    }
    int maxi;
    void search(string s){
        
        trie* t=tree;
            
        if(t->child.find(s)==t->child.end())
           return;
        
        t=t->child[s];
        
        if(t)
         maxi=t->val;
    }
    int f(string pre,string suf){
         reverse(suf.begin(),suf.end());
        string s=suf+"#"+pre;
        
        maxi=-1;
        
        search(s);
        
        return maxi;
    }
    //THIS IS APPROCH 1 BY MAKING 2 TRIE AND STORING VALUE IN SET AND THEN TAKING THEIR INTERSECTION WHICH WILL LEAD TO TLE
//     bool findp(trie* &t,string s,int i){
        
//         if(t->isend && i!=s.length()){
//             maxi=max(maxi,t->val);
//             return false;
//         }
//         if(i==s.length())
//             return true;
        
//         if(t->child.find(s[i])==t->child.end())
//             return false;
//         t=t->child[s[i]];
//         return findp(t,s,i+1);
//     }
//     bool finds(trie* &t,string s,int i){
        
//     }
//     int f(string prefix, string suffix) {
        
//         trie* t=tree;
//         if(prefix=="" && suffix=="")
//             return si;
        
//         if(prefix=="")
//             finds(t,suffix,0);
//         else{
//             if(!findp(t,prefix,0)) return -1;
            
//             if(!t || (suffix!="" && t->isend)) return -1;

//             if(suffix=="" && t->isend) return maxi;

//             finds(t,suffix,0);
//         }
        
//         return maxi;
//     }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */