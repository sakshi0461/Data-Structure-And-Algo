#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int t=s.size(),count=0;
	while(t--){
	    count=count+int(s[t]);
	}
	cout<<count;
	return 0;
}
