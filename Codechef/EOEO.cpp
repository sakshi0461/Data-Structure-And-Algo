#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
  while(t--){
      long long int ts;
      cin>>ts;
      long long int count=0;
      if(ts%2!=0){
          count=(ts-1)/2;
      }
      else{
          long long int p=0,n=ts;
          while(n>0){
              if(n%2==0){
               p++;
               n/=2;
             continue; 
             }
             break;
          }
         long long int js=pow(2,p+1);
          count=ts/js;
      }
      cout<<count<<"\n";
  }
	return 0;
}
