#include <iostream>
using namespace std;

int main() {
int t;
 cin>>t;
 while(t--){
     int n;
     cin>>n;
     int arr[n][n];
     if(n==1){
         cout<<"1\n";
         continue;
         
     }
     int k;
     for(int i=0;i<n;i++){
         k=n*i+1;
         if(k>n*n)
          break;
         for(int j=0;j<n;j++){
             arr[i][j]=k;
             k++;
         }
         i++;
         k=n*i+1;
         if(k>n*n)
          break;
         for(int j=n-1;j>=0;j--){
             arr[i][j]=k;
             k++;
         }
     }
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++)
           cout<<arr[i][j]<<" ";
         cout<<"\n";
     }
 }
	return 0;
}
