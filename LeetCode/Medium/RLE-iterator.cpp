class RLEIterator {
public:
    long long int count=0,si=0;
    vector<long long int>arr;
    vector<long long int>v;
    RLEIterator(vector<int>& A) {
        
         for(int i=0;i<A.size();i+=2){
             if(A[i]==0) continue;
             si+=A[i];
             arr.push_back(A[i+1]);
             v.push_back(si);
         }
        
    }
    
    int bsearch(long long int count){
        int i=0,j=v.size()-1;
        
        while(i<j){
            int mid=i+(j-i)/2;
            
            if(v[mid]==count) return mid;
            else if(v[mid]>count)
                j=mid;
            else
                i=mid+1;
        }
        
        return j;
    }
    int next(int n) {
        
        count+=n;
        if(count>si) return -1;
    
        int p=bsearch(count);
       
        return arr[p];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */