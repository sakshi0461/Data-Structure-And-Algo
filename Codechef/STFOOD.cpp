#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int result,count=0.0;
        while(n--){
            
            double s,p,v;
            cin>>s>>p>>v;
            s++;
             result=floor(p/s)*v;
   //          cout<<floor(p/s)<<"   ";
            if(result>count)
              count=result;
        }
        cout<<(int)count<<"\n";
    }
    return 0;
}