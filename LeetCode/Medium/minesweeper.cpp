class Solution {
public:
    void DFS(vector<vector<char>>&board,int x,int y,int xa[],int ya[]){
        
        if(board[x][y]=='E'){
        int count=0;
        
        for(int i=0;i<8;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            
            if(x0>=0 && y0>=0 && x0<board.size() && y0<board[0].size()){
                if(board[x0][y0]=='M')
                    count++;
            }
        }
        
        if(count==0){
            board[x][y]='B';
         for(int i=0;i<8;i++){
            int x0=x+xa[i];
            int y0=y+ya[i];
            
            if(x0>=0 && y0>=0 && x0<board.size() && y0<board[0].size())
                if(board[x0][y0]=='E')
                    DFS(board,x0,y0,xa,ya);
          }
        }else
            board[x][y]='0'+count;

        }
        
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int x=click[0];
        int y=click[1];
        
        int xa[8]={1,-1,0,0,1,-1,1,-1};
        int ya[8]={0,0,1,-1,1,-1,-1,1};
        
        if(board[x][y]=='M')
            board[x][y]='X';
        else if(board[x][y]=='E')
            DFS(board,x,y,xa,ya);
        
        return board;
    }
};