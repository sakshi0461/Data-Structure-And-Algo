#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
 cin>>t;
 int a[3][t];
 int j=0,c=0;
  while(j<t){
      int i=0,count=0;
   while(i<3){
       cin>>a[i][j];
       if(a[i][j]==1)
       count++;
       i++;
  }
  if(count>=2)
  c++;
  j++;}
cout<<c;
 return 0;
}