class Solution {
public:
    //METHOD 1-BACKTRACKING
    bool funct(vector<vector<int>>&rooms,int i,bool visited[]){
        
        for(int k=0;k<rooms[i].size();k++){
            if(!visited[rooms[i][k]]){
                visited[rooms[i][k]]=true;
                if(funct(rooms,rooms[i][k],visited))
                    return true;
            }
        }
        for(int i=0;i<rooms.size();i++)
            if(!visited[i])
              return false;
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool visited[rooms.size()];
        memset(visited,false,sizeof(visited));
        visited[0]=true;
        return funct(rooms,0,visited);

    }
    //method2- BFS
     bool canVisitAllRooms(vector<vector<int>>& rooms) {
         int n=rooms.size();
         bool visited[n];
         memset(visited,false,sizeof(visited));
         queue<int>q;
         q.push(0);
         visited[0]=true;
         
         while(!q.empty()){
             int i=q.size();
             while(i--){
                 int t=q.front();
                 q.pop();
                 for(int i=0;i<rooms[t].size();i++){
                     if(!visited[rooms[t][i]]){
                         q.push(rooms[t][i]);
                         visited[rooms[t][i]]=true;
                     }
                 }
             }
         }
         
         for(int i=0;i<n;i++){
             if(!visited[i])
                 return false;
         }
         
         return true;
    }
    //METHOD 3-DFS
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
         bool visited[n];
         memset(visited,false,sizeof(visited));
         stack<int>s;
         s.push(0);
         visited[0]=true;
        
        while(!s.empty()){
            int t=s.top();
            s.pop();
            for(int i=0;i<rooms[t].size();i++)
                if(!visited[rooms[t][i]]){
                    s.push(rooms[t][i]);
                    visited[rooms[t][i]]=true;    
                }
        }
         for(int i=0;i<n;i++){
             if(!visited[i])
                 return false;
         }
         
         return true;
    }
};