class Solution {
public:
//     //USING HEAP
//     int networkDelayTime(vector<vector<int>>& times, int N, int K){
//         unordered_map<int,vector<pair<int,int>>>graph;
        
//         for(int i=0;i<times.size();i++)
//             graph[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        
//         int dist[N];

//         for(int i=0;i<N;i++)
//             dist[i]=INT_MAX;
        
//         dist[K-1]=0;
//         int src=K;
//         bool i=true;
        
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        
//         minheap.push(make_pair(0,K));
        
//         while(i){
//           for(auto j:graph[src]){
//                 if(dist[src-1]+j.second<dist[j.first-1]){
//                     dist[j.first-1]=dist[src-1]+j.second;
//                     //THIS IS BECAUSE WE DONT USE HEAP HERE BECAUSE WE WONT BE ABLE TO UPDATE VALUE IN HEAP IN LESS TIME SO BETTER TO USE A SET
//                 }
//             }
//         }
//     }
    //USING VISITED ARRAY AND NORMAL COMARISION
    int networkDelayTime(vector<vector<int>>& times, int N, int K){
        unordered_map<int,vector<pair<int,int>>>graph;
        
        for(int i=0;i<times.size();i++)
            graph[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        
        int dist[N];
        bool visited[N];
        for(int i=0;i<N;i++){
            dist[i]=INT_MAX;
            visited[i]=false;
        }
        
        dist[K-1]=0;
        int src=K;
        bool i=true;
        
        while(i){
            visited[src-1]=true;
            
            for(auto j:graph[src]){
              if(!visited[j.first-1])
                if(dist[src-1]+j.second<dist[j.first-1])
                    dist[j.first-1]=dist[src-1]+j.second;
            }
            
            int mini=INT_MAX,index;
            
            for(int i=0;i<N;i++)
                if(!visited[i] && mini>dist[i]){
                    mini=dist[i];
                    index=i;
                }
            
            if(mini==INT_MAX) return -1;
            else  src=index+1;
        }
        int maxi=INT_MIN;
        for(int i=0;i<N;i++)
            if(maxi<dist[i])
                maxi=dist[i];
    
         return maxi;
    }
 //   USING SET
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,set<pair<int,int>>>graph;
        
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].insert(make_pair(times[i][2],times[i][1]));
        }
        
        int dist[N];
        //set all dist to infinite
        for(int i=0;i<N;i++)
            dist[i]=INT_MAX;
        //dist of src is 0
        dist[K-1]=0;
        //make a set which will act as a queue
        set<pair<int,int>>s;
        s.insert(make_pair(0,K));
        
        while(!s.empty()){
            
            pair<int,int>dest=*(s.begin());
            
            s.erase(s.begin());
            
            for(auto j:graph[dest.second]){
              if(j.first+dest.first<dist[j.second-1]){
                  dist[j.second-1]=j.first+dest.first;
                  
                  auto f=s.find(j);
                  
                  if(f!=s.end())
                      s.erase(f);
                  
                  s.insert(make_pair(dist[j.second-1],j.second));
              }
            }
        }
        
        int maxi=INT_MIN;
        
        for(int i=0;i<N;i++)
            if(dist[i]>maxi)
                maxi=dist[i];
        if(maxi==INT_MAX) return -1;
          return maxi;
    }
};