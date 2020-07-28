#include<bits/stdc++.h>
using namespace std;
int min(vector<int>insert){
	int minimum=insert.back();
	while(insert.size()){
		insert.pop_back();
      if(insert.back()!=0 && minimum>=insert.back())
      	minimum=insert.back();
	}
	return minimum;
}
bool calculate(int c,int m,int k,int l,int r){
         if(m==0){
         	if(c>=l && c<=r)
         		return true;
         	else
         		return false;
         }
         if(c>k+1)
         	return calculate(c-1,m-1,k,l,r);
         else if(c<k-1)
         	return calculate(c+1,m-1,k,l,r);
         else 
         	return calculate(k,m-1,k,l,r);

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k,l,r;
        cin>>n>>m>>k>>l>>r;
        vector<int>insert;
        while(n--){
          int c,p;
          cin>>c>>p;
          if(calculate(c,m,k,l,r))
          insert.push_back(p);
        }
   if(insert.empty())
    	cout<<"-1\n";
   else
     cout<<min(insert)<<"\n";
	}
	return 0;
}