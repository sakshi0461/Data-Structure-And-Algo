#include <iostream>
using namespace std;

int main() {
int t;
cin>>t;
  while(t--){
      int n,k;
      cin>>n>>k;
      int a[n];
      int sum=0,sum2=0;
      for(int i=0;i<n;i++){
          cin>>a[i];
          sum2+=a[i];
          if(a[i]>k)
           sum+=k;
          else
           sum+=a[i];
      }
      cout<<sum2-sum<<"\n";
  }
	return 0;
}
