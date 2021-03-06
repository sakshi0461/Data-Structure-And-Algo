class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s1,s2;
    MyQueue() {
        s1=stack<int>();
        s2=stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int t=s1.top();
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    /** Get the front element. */
    int peek() {
         while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        int t=s1.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */