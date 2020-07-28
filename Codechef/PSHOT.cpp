/*#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,a=0,j=0,index=0,b=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<2*n;i++){
      if(max(a,b)-min(a,b)>n-((i+1)/2))
       {index=i;
       j=1;
       break;}
       if(i%2==0 && s[i]=='1')
       a++;
       else if(i%2!=0 && s[i]=='1')
       b++;
    }
    if(j==1)
    cout<<index+1<<"\n";
    else
    cout<<2*n<<"\n";
    
  }
}*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
for(int i=0;i<t;i++)
{
string s;
int n;
cin>>n;
cin>>s;
int a=0,b=0,c=0;
int counta=0,countb=0;
for(int j =0;j<2*n;j++)
{
	if(j%2==0)
	{	counta++;
		if(s[j]=='1')
		{a++;}	
	}
	else if(j%2!=0)
	{countb++;
		if(s[j]=='1')
		{b++;}
	}
	
	if(a-b>n-countb)
	{cout<<j+1<<endl;
	c=1;
		break;
	}
	if(b-a>n-counta)
	{cout<<j+1<<endl;
	c = 1;
		break;
	}	
}
if(c==0)
{cout<<2*n<<endl;}	
}	
	
	return 0;
}
