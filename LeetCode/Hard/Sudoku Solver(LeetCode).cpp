class Solution {
public:
    bool issafe(vector<vector<char>>&board,int row,int col,int val){
        char x=val+'0';
        
        for(int i=0;i<board.size();i++){
           if(i==row) continue;
            if(board[i][col]==x)
                return false;
        }
        
        for(int i=0;i<board[row].size();i++){
            if(i==col) continue;
            if(board[row][i]==x)
                return false;
        }
        
        for(int i=3*(row/3);i<3*(row/3)+3;i++){
            for(int j=3*(col/3);j<3*(col/3)+3;j++){
                if(i==row && j==col) continue;
                if(board[i][j]==x)
                  return false;
            }
        }
        
        return true;
    }
    bool nextassigned(vector<vector<char>>&board,int &row,int &col){
        
        for(int j=col;j<board[row].size();j++)
            if(board[row][j]=='.'){
                col=j;
                return true;
            }
        
        for(int i=row+1;i<board.size();i++){
            for(int j=0;j<board[row].size();j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        
        return false;
    }
    bool solve(vector<vector<char>>&board,int row,int col){
        
        if(!nextassigned(board,row,col))
            return true;
        
        for(int i=1;i<=9;i++){
            if(issafe(board,row,col,i)){
               board[row][col]=i+'0';
                if(solve(board,row,col))
                    return true;
               board[row][col]='.';
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};