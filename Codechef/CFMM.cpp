#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        int n;
        scanf("%d\n",&n);
        char array[10000000];
        int i=0;
        int arr[6],z=6;
        while(z--)
        {arr[z]=0;} 
        while(n--)
        {scanf("%s\n",array);
        
       
          i=0;
          //  i++;
          while(array[i]!='\0')
          {
              if(array[i]=='c')
              arr[0]++;
              if(array[i]=='o')
              arr[1]++;
              if(array[i]=='d')
              arr[2]++;
              if(array[i]=='e')
              arr[3]++;
              if(array[i]=='h')
              arr[4]++;
              if(array[i]=='f')
              arr[5]++;
              
              i++;
          }
         
        }
          int m=0,c=0;
          for(int i=0;;i++)
            {if(arr[0]>=(2*i) && arr[1]>=i && arr[2]>=i && arr[3]>=(2*i) && arr[4]>=i && arr[5]>=i)
                           c=i;
             
               
              else 
              break;
          }
          printf("%d\n",c);
 
       
    }
    return 0;
}