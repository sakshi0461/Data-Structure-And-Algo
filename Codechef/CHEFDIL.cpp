#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    
	    string s;
	    cin>>ws;
	    cin>>s;
	    int i=0,actual=0,counter;
	    int size=s.size();
	    while(size--)
	    {
	        if(s[size]=='1')
	       counter++;
	    }
	   // cout<<counter;
	    if(counter%2!=0)
	    cout<<"WIN\n";
	    else
	    cout<<"LOSE\n";
	    counter=0;
	}
	return 0;
}
