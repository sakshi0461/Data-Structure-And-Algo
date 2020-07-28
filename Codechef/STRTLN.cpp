#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long int find(ll n){
    if(n<2)
    return 0;
    return (n*(n-1))/2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
      ll result=0,x[100000]={0},y[100000]={0},b=0,a=0;
        ll array[n][2];
        for(int i=0;i<n;i++){
            cin>>array[i][0]>>array[i][1];
            x[array[i][0]]++;
            y[array[i][1]]++;
        }
        for(int i=0;i<100000;i++){
             if(x[i]>=2)
            a+=find(x[i]);
            if(y[i]>=2)
           b+=find(y[i]);
        }
       // cout<<a<<" "<<b<<"\n";
         result=find(n)-a-b;
        cout<<result<<"\n";
    }
}