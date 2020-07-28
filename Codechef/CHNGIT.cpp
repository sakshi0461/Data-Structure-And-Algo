#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n,i=0;
    cin>>n;
    int a[n],c[100]={0};
    while(i<n){
        cin>>a[i];
        c[a[i]]++;
    //    cout<<c[a[i]];
        i++;
    }

    int d=*max_element(c,c + 100); 
  cout<<n-d<<"\n";
    }
    return 0;
}