#include <iostream> 
using namespace std; 
  
int countunsetbits(int n) 
{ 
    int count = 0;  
    for (int x = 1; x <= n; x = x<<1)  
        if ((x & n) == 0) 
            count++;      
  
    return count;  
} 
int main() 
{ int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    cout << countunsetbits(n)<<"\n"; 
    
} 
    return 0; 
} 