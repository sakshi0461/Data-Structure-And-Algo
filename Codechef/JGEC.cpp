#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,s="JGEC";
        cin>>a;
        if(a.length()!=n)
        cout<<"0\n";
        else{
        int count=0;
        for(int i=0;;i++){
            size_t found=a.find(s);
            if(found!=string::npos){
            count++;
            a.erase(0,found+(s.length()-1));
    //        cout<<found<<" "<<a.length()<<" "<<s.length()<<"\n";
            }
            if(found==string::npos)
            break;
        }
        cout<<count<<"\n";}
    }
}