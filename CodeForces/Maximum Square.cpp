#include<bits/stdc++.h>
using namespace std;
int calculate(int i,vector<int>v,int n){
if(v[i]>=n){
    cout<<n<<"\n";
    return 0;
}
return calculate(i+1,v,n-1);

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i=0;
        cin>>n;
        vector<int>v;
        while(i<n){
            int y;
            cin>>y;
            v.push_back(y);
            i++;
        }
        sort(v.begin(),v.end());
  
    calculate(0,v,n);
    }
    return 0;
}