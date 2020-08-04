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
void find(string s,vector<string>&v,vector<vector<char>>board,int xa[],int ya[],int x0,int y0,trie* t){
    
        if(t->isend){
            t->isend=false;
            v.push_back(s);
        }
        if(t->child.size()==0)
            return;
    
        for(int i=0;i<4;i++){
            int x=xa[i]+x0;
            int y=ya[i]+y0;
            if(x>=0 && y>=0 && x<board.size() && y<board[0].size())
                if(t->child.find(board[x][y])!=t->child.end()){
                    char xx=board[x][y];
                    board[x][y]='.';
                    find(s+xx,v,board,xa,ya,x,y,t->child[xx]);
                    board[x][y]=xx;
                }
        }
        
        return;
    }
    void search(vector<vector<char>>&board,vector<string>&v){
        
        int xa[4]={1,-1,0,0};
        int ya[4]={0,0,1,-1};
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(tree->child.find(board[i][j])!=tree->child.end()){
                   char x=board[i][j];
                    string s(1,x);
                    board[i][j]='.';
                    find(s,v,board,xa,ya,i,j,tree->child[x]);
                    board[i][j]=x;
                }
            }
        }
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& word) {
        
        vector<string>v;
       tree=newnode();
      for(int k=0;k<word.size();k++)
         insert(word[k]);
        
      search(board,v);
        
        sort(v.begin(),v.end());
      return v;
    }
};