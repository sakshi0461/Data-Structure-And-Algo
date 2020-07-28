class Solution {
public:
    int countPrimes(int n) {
      int count=0;
      vector<bool>visited(n+1,true);
      
      for(int i=2;i<n;i++){
        if(visited[i]){
          count++;
       //   cout<<i<<" ";
          for(int j=i;j<n;j+=i)
            visited[j]=false;
        }
      }
      return count;
    }
};