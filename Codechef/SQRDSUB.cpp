#include <bits/stdc++.h>
using namespace std;
long long int squred(long long int arr[],long long int n,long long int sum){
     unordered_map<long long int,long long int> prevSum; 
    long long int res =0; 
    long long int currsum = 0; 
  
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == sum)  
            res++;         
        if (prevSum.find(currsum - sum) !=  prevSum.end())  
            res += (prevSum[currsum - sum]); 
        prevSum[currsum]++; 
    } 
    res-=(n*(n+1))/2;
    return abs(res); 
}
int main() {
 int t;
 cin>>t;
 while(t--){
    long long int n;
    cin>>n;
    long long int a[n];
    long long int array[n]={0};
    for(int i=0;i<n;i++){
    cin>>a[i];
    if(abs(a[i])%4==0)
    array[i]=2;
    else if(abs(a[i])%2==0)
    array[i]=1;
    else
    array[i]=0;
    }
    cout<<squred(array,n,1)<<"\n";
 }
	return 0;
}
