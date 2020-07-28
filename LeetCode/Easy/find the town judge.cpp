class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1) return N;
        vector<int>adj[N];
        for(int i=0;i<trust.size();i++){
            adj[trust[i][0]-1].push_back(trust[i][1]-1);
        }
        int judge=-1;
        for(int i=0;i<N;i++){
            if(adj[i].size()==0){
              for(int j=0;j<N;j++){
                  if(j==i) 
                      continue;
                  if(find(adj[j].begin(),adj[j].end(),i)!=adj[j].end())
                      judge=i+1;
                  else{
                      judge=-1;
                      break;
                  }
              }
            }
        }
        return judge;
    }
    int findJudge(int N, vector<vector<int>>& trust){
        int in[N];
        int out[N];
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=0;i<trust.size();i++){
            in[trust[i][0]-1]++;
            out[trust[i][1]-1]++;
        }
        
        for(int i=0;i<N;i++){
           if(in[i]==0 && out[i]==N-1)
               return i+1;
        }
        return -1;
    }
};