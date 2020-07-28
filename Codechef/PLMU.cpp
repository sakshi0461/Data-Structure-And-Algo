#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i=0,c1=0,c2=0;
        cin>>n;
        int a[n],b[n];
        while(i<n){
           cin>>a[i];
           if(a[i]==2)
           c1++;
           else if(a[i]==0)
           c2++;
           i++;
        }
        int c=(((c1*(c1-1))/2)+((c2*(c2-1))/2));
       cout<<c<<"\n";
    }
    return 0;
}
