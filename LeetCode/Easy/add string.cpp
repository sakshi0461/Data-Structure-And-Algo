class Solution {
public:
    string addStrings(string nums1, string nums2) {
        int n1=0,n2=0,carry=0;
        string s="";
        int i1=nums1.length()-1,i2=nums2.length()-1;
        
        while(i1>=0 && i2>=0){
            n1=nums1[i1]-48;
            n2=nums2[i2]-48;
            string o=to_string((n1+n2+carry)%10);
            s+=o;
            carry=((n1+n2+carry)-((n1+n2+carry)%10))/10;
            i1--;
            i2--;
        }
        n1=0;
        n2=0;
        if(i1>=0){
            while(i1>=0){
                n1=nums1[i1]-48;
                string o=to_string((carry+n1+n2)%10);
               s+=o;
                carry=((n1+n2+carry)-((n1+n2+carry)%10))/10;
                i1--;
            }
            cout<<s<<" ";
        }
        else if(i2>=0){
            while(i2>=0){
               n2=nums2[i2]-48;
                string o=to_string((carry+n1+n2)%10);
                s+=o;
             carry=((n1+n2+carry)-((n1+n2+carry)%10))/10;
                i2--;
            }
            cout<<s<<" ";
        }
        
        if(carry!=0){
         string o=to_string(carry);
            s+=o;
         //   cout<<carry<<" ";
        }
        
        reverse(s.begin(),s.end());
        
        return s;
    }
};