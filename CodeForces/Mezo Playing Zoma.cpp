#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,l=0,r=0;
    cin>>t;
    string a;
    cin>>a;
    int i=0;
    while(i<a.size()){
        if(a[i]=='L')
        l++;
        else if(a[i]=='R')
        r++;
i++;
    }
    int out=r+l+1;
    cout<<out;
}