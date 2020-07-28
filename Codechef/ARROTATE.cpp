#include <iostream>
using namespace std;

int main() {
int t;
cin>>t;
while(t--){
    int n,m,i=0,j=0;
    cin>>n>>m;
    int a[n],b[m];
    while(i<n){
        cin>>a[i];
        i++;
    }
    i=0;
    while(i<m){
        cin>>b[i];
        i++;
    }
    i=0;int count=0;
    while(j<n){
        count=0;
        i=0;
    while(i<m){
        if(a[j]==b[i])
          {count=1;
            break;
          }
          
        i++;
             }
             if(count==0)
             cout<<a[j]<<" ";
        j++;
             }
    i=0;
    while(i<m){
       cout<<b[i]<<" ";
        i++;
    }
    cout<<"\n";
}
	return 0;
}
