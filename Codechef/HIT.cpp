#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
       int n,i=0;
       cin>>n;
       vector<int>v;
       while(i<n){
           int y;
           cin>>y;
           v.push_back(y);
           i++;
       }
       sort(v.begin(),v.end());
       n=n/4;
       int x=v[n];
       int y=v[2*n];
       int z=v[3*n];
       int d=x+y+z;
       if(v[n-1]!=v[n] && v[(2*n)-1]!=v[2*n] && v[(3*n)-1]!=v[3*n])
       cout<<x<<" "<<y<<" "<<z<<"\n";
       else
       cout<<"-1\n";
   }
	return 0;
}
