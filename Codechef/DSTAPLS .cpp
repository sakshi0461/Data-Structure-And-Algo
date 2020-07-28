#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,k;
	    cin>>n>>k;
	    if(k==1)
	    cout<<"NO"<<"\n";
	    else {
	        if((n/k)%k==0)
	        cout<<"NO"<<"\n";
	        else
	        cout<<"YES"<<"\n";
	    } 
	 }
	return 0;
}
