#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void find(ll n,ll count){
  //cout<<n<<" "<<count<<" ";
  ll d;
   if(n<10)
  {cout<<count<<"\n";
  return;}
  d=n-(floor(n/10)*10);
  count+=floor(n/10);
  n=d+floor(n/10);
  find(n,count);
}
int main(){
ll t;
cin>>t;
while(t--){
  ll n;
 cin>>n;
 find(n,n);
}
return 0;
}