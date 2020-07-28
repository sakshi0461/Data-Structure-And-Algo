class Solution {
public:
    bool find(vector<vector<char>>&board,string s,int i,int j,int l){
        
        if(l==s.size()) return true; 
       
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; 
        
        if(board[i][j]!=s[l]) return false; 
        
        board[i][j] = '*'; 
        
        bool furtherSearch =  find(board, s, i+1, j, l+1) || 
                              find(board, s, i-1, j, l+1) || 
                              find(board, s, i, j-1, l+1) ||
                              find(board, s, i, j+1, l+1);   
        
        board[i][j] = s[l]; 
        return furtherSearch;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        
        int xa[4]={0,0,-1,1};
        int ya[4]={1,-1,0,0};
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]==word[0])
                    if(find(board,word,i,j,0))
                        return true;
        
       return false; 
    }
};