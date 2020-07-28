class Solution {
public:
    bool issafe(vector<vector<char>>&board,int row,int col){
        char x=board[row][col];
        
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
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int row=0;row<board.size();row++)
            for(int col=0;col<board[row].size();col++)
                if(board[row][col]!='.' && !issafe(board,row,col)){
                  //  cout<<row<<" "<<col<<" ";
                    return false;
                }
        
        return true;
    }
};