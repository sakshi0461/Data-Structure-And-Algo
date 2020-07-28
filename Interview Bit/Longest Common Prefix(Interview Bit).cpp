#define mod 1000000007
void istrue(int i1,int i2,int k,vector<string>&v,int &count){
    
    string s=v[i1];
    if(s.length()<=k-1) count++;
    for(int i=i1+1;i<=i2;i++){
        int j;
        for(j=0;j<v[i].length();j++){
            if(j==s.length()) break;
            if(s[j]!=v[i][j])
              break;
        }
        s=s.substr(0,j);
        if(s.length()<=k-1)
          count=(count%mod+1)%mod;
    }
      
     return;
}
void combi(int n,vector<string>&v,int start,int k,int &count){
    if(start>n) return;
    
     istrue(start,n,k,v,count);
     
     combi(n,v,start+1,k,count);
}
int Solution::LCPrefix(vector<string> &A, int B) {
    
    int n=A.size();
    int count=0;
    combi(n-1,A,0,B,count);
    count=((((n%mod)*((n+1)%mod))/2)%mod-count%mod)%mod;
    return count%mod;
}
