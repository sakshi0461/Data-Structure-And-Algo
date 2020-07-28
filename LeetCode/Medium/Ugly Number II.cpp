class Solution {
public:
  //METHOD 1-NAIVE but TLE
   // bool ugly(int n){
   //   while(n%2==0){
   //     n/=2;
   //   }
   //   while(n%3==0)
   //     n/=3;
   //   while(n%5==0)
   //     n/=5;
   //   if(n==1)
   //     return true;
   //   else
   //     return false;
   // }
   // int nthUglyNumber(int n) {
   //    int count=0;
   //   for(int i=1;;i++){
   //     if(ugly(i))
   //       count++;
   //     if(count==n)
   //       return i;
   //   }
   //   return 0;
   //  }
  //METHOD 2- DP
    int nthUglyNumber(int n) {
      int ugly2=2,ugly3=3,ugly5=5;
      vector<int>v;
      v.push_back(1);
      n--;
      int i=1,j=1,k=1,t;
      while(n--){
        t=min(ugly2,min(ugly3,ugly5));
    //     cout<<t<<" "<<ugly2<<" "<<ugly3<<" "<<ugly5<<"\n";
        v.push_back(t);
        if(t==ugly2){
          ugly2=v[i]*2;
          i++;
        }
        if(t==ugly3){
          ugly3=v[j]*3;
          j++;
        }
        if(t==ugly5){
          ugly5=v[k]*5;
          k++;
        }
      }
      return v[v.size()-1];
    }
};