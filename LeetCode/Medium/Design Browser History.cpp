class BrowserHistory {
public:
    deque<string>q;
    int it;
    BrowserHistory(string homepage) {
        q.push_back(homepage);
        it=0;
    }
    
    void visit(string url) {
        while((q.size()-1)!=it)
            q.pop_back();
        q.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it>0 && steps--)
            it--;
        return q[it];
    }
    
    string forward(int steps) {
        while(it<q.size()-1 && steps--)
            it++;
        return q[it];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */