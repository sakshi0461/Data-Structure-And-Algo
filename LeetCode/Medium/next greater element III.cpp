class Solution {
public:
    void create(int arr[],int start,int end){
        int i=end,mini=INT_MAX,indexi=-1,indexj=-1;
        bool p=true;
        while(i>=start && p){
            int j=i+1;
            while(j<=end){
                if(arr[i]<arr[j] && mini>arr[j]){
                    mini=arr[j];
                    indexi=i;
                    indexj=j;
                    p=false;
                }
                j++;
            }
            i--;
        }
        if(indexi!=-1 && indexj!=-1){
         swap(arr[indexi],arr[indexj]);
         sort(arr+indexi+1,arr+end+1);
        }
         return;
    }
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int arr[s.length()];
        int n0=n;
        for(int i=s.length()-1;i>=0;i--){
            arr[i]=n%10;
            n/=10;
        }
        create(arr,0,s.length()-1);
         int num=0;
        for(int i=0;i<s.length();i++){
          if(num>INT_MAX/10) return -1;
            num=num*10+arr[i];
        }
        if(num>n0) return num;
        return -1;
    }
};