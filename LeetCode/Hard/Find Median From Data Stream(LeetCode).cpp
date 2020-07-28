class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double>maxheap;
    priority_queue<double,vector<double>,greater<double>>minheap;
    MedianFinder() {
     //   minheap.clear();
       // maxheap.clear();
    }
    
    void addNum(int n) {
        double num=(double)n;
        if(minheap.size()==maxheap.size()){
            if(minheap.size()==0){
                maxheap.push(num);
                return;
            }
            if(num<=minheap.top())
                maxheap.push(num);
            else{
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }
        }
        else{
          if(num>=maxheap.top())
            minheap.push(num);
          else{
              minheap.push(maxheap.top());
              maxheap.pop();
              maxheap.push(num);
          }
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size())
            return (maxheap.top()+minheap.top())/2;
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */