#include<bits/stdc++.h>
using namespace std;
int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}
int leap(int year){
  if (year % 400 == 0)  
        return 1;  
    if (year % 100 == 0)  
        return 0;  
    if (year % 4 == 0)  
        return 1;  
    return 0;
}
void hii(int y1,int y2){
  int count=0;
  for(int i=y1;i<=y2;i++)
      {if(dayofweek(1,2,i)==6)
      count++;
      else if(leap(i)==0 && dayofweek(1,2,i)==0)
      count++;
      }
  cout<<count;
}
void find(int m1,int m2,int y1,int y2){
 if(m1<=2){
   if(m2>=2)
   hii(y1,y2);
   else
   hii(y1,y2-1);
 }
 else{
   if(m2>=2)
   hii(y1+1,y2);
   else
    hii(y1+1,y2-1);
 }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
  int t;
  cin>>t;
  while(t--){
    int m1,m2,y1,y2;
    cin>>m1>>y1>>m2>>y2;
    int temp;
    if(y1>y2)
    {temp=y1;
        y1=y2;
        y2=temp;
        temp=m1;
        m1=m2;
        m2=temp;
    }
    if(y1==y2 && m2<m1)
    {
        temp=m1;
        m1=m2;
        m2=m1;
    }
    find(m1,m2,y1,y2);
   cout<<"\n";
  }
}