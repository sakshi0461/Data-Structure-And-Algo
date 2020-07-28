class MinStack {
public:
    /** initialize your data structure here. */
    int sta[1000000];
    int t;
    vector<int>mini;
    MinStack() {
        mini.clear();
        mini.push_back(INT_MAX);
        t=-1;
    }
    
    void push(int x) {
        t++;
        sta[t]=x;
        if(x<=mini[mini.size()-1])
            mini.push_back(x);
    }
    
    void pop() {
        if(sta[t]==mini[mini.size()-1])
            mini.pop_back();
        t--;
    }
    
    int top() {
        return sta[t];
    }
    
    int getMin() {
        return mini[mini.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */