class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n=image.size();
        int m=image[0].size();
        
        int dirx[4]={0,0,1,-1};
        int diry[4]={1,-1,0,0};
        
        queue<pair<int,int>>q;
        bool visited[n][m];
        memset(visited,false,sizeof(visited));
        
        q.push(make_pair(sr,sc));
        visited[sr][sc]=true;
        
        int color=image[sr][sc];
        image[sr][sc]=newColor;
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            
            int x=p.first;
            int y=p.second;
            
            for(int i=0;i<4;i++){
               int x0=x+dirx[i];
               int y0=y+diry[i];
                
                if(x0>=0 && y0>=0 && x0<n && y0<m)
                    if(image[x0][y0]==color && !visited[x0][y0]){
                        image[x0][y0]=newColor;
                        q.push(make_pair(x0,y0));
                        visited[x0][y0]=true;
                    }
            }
        }
        
        
        return image;
    }
};