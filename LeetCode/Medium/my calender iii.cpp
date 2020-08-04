class MyCalendarThree {
public:
    //In this ques we need to find till ith booking maximum number of overlapping booking happened not on ith booking how many overlapping are there between start and end in ith booking
    map<int,int>mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        
        mp[start]++;
        mp[end]--;
        
        int maxi=0,count=0;
        
        for(auto i=mp.begin();i!=mp.end();i++){
            count+=i->second;
            if(maxi<count)
                maxi=count;
        }
        
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */