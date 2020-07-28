#include <bits/stdc++.h>
using namespace std;
int maxi(int a[]){
 int i=0,index,maximum=-2;
 while(i<3){
     if(maximum<=a[i])
    { maximum=a[i];
    index=i;}
     i++;
 }
 return index;
}
int find(int a[],int c[]){
int i=0;
    while(i<3){
        i++;
        int b=maxi(a);
        int s=maxi(c);
        int e=c[s];
        int d=a[b];
        a[maxi(a)]=-1;
        if(d==a[maxi(a)]){
            if(c[b]==c[maxi(a)]){
                c[b]=-1;
                continue;
            }
            return 0;
        }
         c[maxi(c)]=-1;
    if(b==s){
        if(e==c[maxi(c)])
        return 0;
    continue;
    }
    return 0;
    }
    return 1;
}
int main() {
     int t;
     cin>>t;
     while(t--){
        int a[3],c[3],i=0;
        while(i<3){
            cin>>a[i];
            i++;
        }
        i=0;
        while(i<3){
            cin>>c[i];
            i++;
        }
       if(find(a,c)==0)
       cout<<"NOT FAIR\n";
       else
       cout<<"FAIR\n";
    
 //   cout<<maxi(a)<<" "<<maxi(c)<<"\n";
         
     }
	return 0;
}
