#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
}
void fun(int A,int B){
   int U,V;
   int count=0;
   while(B>0){
       count++;
        U=A^B;
        V=A&B;
       A=U;
       B=V*2;
   }
  cout<<count<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int q=stoi(a,nullptr,2);
int w=stoi(b,0,2);
       fun(q,w);
    }
    return 0;
}
