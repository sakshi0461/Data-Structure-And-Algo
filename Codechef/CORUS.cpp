#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    
	    string s;
	    cin>>s;
	    
	    int a[26]={0};
	    int maxi=INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        a[s[i]-'a']++;
	        if(a[s[i]-'a']>maxi)
	          maxi=a[s[i]-'a'];
	    }
	    
	    
	    while(q--){
	        
	        int c;
	        cin>>c;
	        int count=0;
	        if(c>=maxi)
	         count=0;
	        else{
	          for(int i=0;i<26;i++){
	            if(a[i]>c)
	             count+=a[i]-c;
	            }
	        }
	        
	        cout<<count<<"\n";
	    }
	}
	return 0;
}
