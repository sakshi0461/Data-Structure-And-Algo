#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        int a[8]={0};
        while(n--){
            int q,b;
            cin>>q>>b;
            if(b>a[q-1])
            a[q-1]=b;
        }
sum = accumulate(a, a+8, sum);
cout<<sum<<"\n";
    }
    return 0;
}
