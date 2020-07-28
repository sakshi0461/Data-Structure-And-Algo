class Solution {
public:
//CORRECT METHOD USING GRAPHS , MAKE A REVERSE GRAPH FROM ENDWORD AND THEN DO DFS FROM THE END WORD IF IT //LEAD TO BEGINWORD THEN PRINT THE MINIMUM NUMBER OF VERTEX IN BETWEEN CONVERSION ELSE RETURN 0
//      bool check(string word1,string word2){
//         if(word1.length()!=word2.length())
//              return false;
         
//           int count=0;
        
//          for(int i=0;i<word1.length();i++)
//              if(word1[i]!=word2[i]){
//                  if(count>=1) return false;
//                  count++;
//              }
         
//          return true;
//      }
//    // METHOD 1
//      int BFS(unordered_map<string,vector<string>>&graph,unordered_map<string,bool>&visited,string word1,string word2){
//          string src=word1;
         
//          queue<pair<string,int>>q;
//          q.push(make_pair(src,1));
//          visited[src]=true;
         
//          while(!q.empty()){
//              pair<string,int> s=q.front();
//              q.pop();
             
//              for(auto j:graph[s.first]){
//                  if(!visited[j]){
//                   if(j==word2) return s.second+1;
//                    visited[j]=true;
//                    q.push(make_pair(j,s.second+1));
//                  }
//              }
//          }
//          return 0;
//      }
     
   // METHOD 2
// void BFS2(queue<string>&q,unordered_map<string,bool>&visited,unordered_map<string,int>&dist,unordered_map<string,vector<string>>&graph){
//          string p=q.front();
//          q.pop();
//          for(auto j:graph[p]){
//              if(!visited[j]){
//                  visited[j]=true;
//                  q.push(j);
//                  dist[j]=dist[p]+1;
//              }
//          }
//      }
//      int bidirBFS(unordered_map<string,vector<string>>&graph,string word1,string word2,vector<string>&wordlist,int V){
        
//          queue<string>s,t;
//          s.push(word1);
//          t.push(word2);
         
//          unordered_map<string,bool>s_visited(V),t_visited(V);
//          unordered_map<string,int>s_dist(V),t_dist(V);
//          for(int i=0;i<V;i++){
//              s_visited[wordlist[i]]=false;
//              t_visited[wordlist[i]]=false;
//              s_dist[wordlist[i]]=0;
//              t_dist[wordlist[i]]=0;
//          }
//          s_dist[word1]=1;
//          t_dist[word2]=1;
//          s_visited[word1]=true;
//          t_visited[word2]=true;
         
//          while(!s.empty() && !t.empty()){
             
//              BFS2(s,s_visited,s_dist,graph);
//              BFS2(t,t_visited,t_dist,graph);
//              int count=0,index;
//              for(int i=0;i<V;i++)
//                  if(s_visited[wordlist[i]] && t_visited[wordlist[i]]){
//                      count++;
//                      index=i;
//                  }
//                if(count>=1)
//                  return s_dist[wordlist[index]]+t_dist[wordlist[index]]-1;
//          }
         
//          return 0;
//      }
//      int ladderLength(string word1, string word2, vector<string>& wordlist) {
//         if(word1.length()!=word2.length() || find(wordlist.begin(),wordlist.end(),word2)==wordlist.end())             return 0;
//         wordlist.push_back(word1);
         
//          int n=wordlist.size();
        
//          unordered_map<string,vector<string>>graph(n);
//          unordered_map<string,bool>visited(n);
         
//          for(int i=0;i<n;i++){
//              visited[wordlist[i]]=false;
//              for(int j=0;j<n;j++){
//                   if(j!=i && check(wordlist[i],wordlist[j]))
//                       graph[wordlist[i]].push_back(wordlist[j]);
//              }
//          }
         
//          return BFS(graph,visited,word1,word2);
//         // return bidirBFS(graph,word1,word2,wordlist,n);
//     }
    //METHOD 3
    int ladderLength(string word1, string word2, vector<string>&wordlist) {
        if(word1.length()!=word2.length() || find(wordlist.begin(),wordlist.end(),word2)==wordlist.end())             return 0;
        unordered_set<string>dict(wordlist.begin(),wordlist.end());
     
       queue<pair<string,int>>q;    
       q.push(make_pair(word1,1));
    
       while(!q.empty()){
         pair<string,int> s=q.front();
           q.pop();
           if(s.first==word2) return s.second;
               for(int i=0;i<s.first.length();i++){
                   char x=s.first[i];
                   for(int j=0;j<26;j++){
                       if(s.first[i]=='a'+j) continue;
                       s.first[i]='a'+j;
                       auto d=dict.find(s.first);
                       if(d!=dict.end()){
                           q.push(make_pair(s.first,s.second+1));
                           dict.erase(d);
                       }
                      s.first[i]=x;
                   }
               }
       }
    
      return 0;
    }
};


