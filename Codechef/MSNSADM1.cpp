#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n],b[n],c[n];
	    int i=0;
	    while(i<n && cin>>a[i])
	    i++;
	    i=0;
	    while(i<n && cin>>b[i])
	    i++;
	    int max=0;
	    while(n--){
	        c[n]=(20*a[n])-(10*b[n]);
	        if(c[n]<0)
	        c[n]=0;
	        if(max<=c[n])
	        max=c[n];
	   }
	   cout<<max<<"\n";
	}
	return 0;
}
