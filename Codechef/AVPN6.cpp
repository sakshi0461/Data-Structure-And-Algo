#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i=0;
	    cin>>n;
	    int a[n];
	    while(i<n){
	        cin>>a[i];
	        i++;
	    }
	    int max=a[0],min=a[0];
	    while(n--){
	        if(max<a[n])
	        max=a[n];
	        if(min>a[n])
	        min=a[n];
	    }
	    cout<<min<<" "<<max<<"\n";
	}
	return 0;
}
