#include<stdio.h>
int main()
{long long int t,r;
scanf("%llu %llu",&t,&r);
for(int i=0;i<t;i++)
{long long int n;
scanf("%llu ",&n);
if(n>=r)
printf("Good boi\n");
else
printf("Bad boi\n"); }
return 0;}