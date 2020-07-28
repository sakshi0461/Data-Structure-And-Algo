#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,a,b,c,i=0;
        cin>>n>>a>>b>>c;
        ll array[n],result,min;
        cin>>array[0];
        min=abs(array[0]-a)+abs(array[0]-b)+c;
        i++;
        while(i<n){
         cin>>array[i];
           result=abs(array[i]-a)+abs(array[i]-b)+c;
          // cout<<result<<"    ";
           if(result<min)
           min=result;
             i++;
        }
        cout<<min<<"\n";
    }
    return 0;
}
