class Solution {
public:
    int generate(int num){
      int k=0;
      while(num>0){
        k+=num%10;
        num/=10;
      }
      return k;
    }
//     int addDigits(int num) {
//       int k=0;
      
//       while(num>0){
//         k=generate(num);
//         num=k;
//         if(k>=0 && k<=9)
//           break;
//       }
//       return k;
//     }
     int addDigits(int num) {
      if(num==0) return 0;
      else if(num%9==0) return 9;
      else return num%9;
    }
};