#include<bits/stdc++.h>
using namespace std;
int composite(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
        return 1;
    }
    return 0;
}
int main(){
    int n,c=0;
    cin>>n;
    for(int i=4;;i++){
        if(composite(i)==1 && composite(n+i)==1)
            {cout<<i+n<<" "<<i;
            break;}
    }
    return 0;
}