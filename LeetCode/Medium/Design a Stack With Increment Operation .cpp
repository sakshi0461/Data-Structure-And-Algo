class CustomStack {
public:
    deque<int>s;
   // stack<int>s1;
    int cap;
    CustomStack(int maxSize) {
        cap=maxSize;
        s=deque<int>();
        //s1=stack<int>();
    }
    
    void push(int x) {
        if(s.size()<cap)
            s.push_back(x);
    }
    
    int pop() {
        if(s.empty())
            return -1;
        int t=s.back();
        s.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        for (auto it = s.begin(); it != (k > s.size() ? s.end() : s.begin() + k); ++it)
            *it += val;
//         int si=s.size()-k;
//         if(s.size()<=k)
//             si=0;
        
//         while(si--){
//             s1.push(s.top());
//             s.pop();
//         }
//         while(!s.empty()){
//             s1.push(s.top()+val);
//             s.pop();
//         }
//         while(!s1.empty()){
//             s.push(s1.top());
//             s1.pop();
//         }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */