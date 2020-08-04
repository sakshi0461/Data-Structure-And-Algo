class MyCalendarTwo {
public:
    vector<vector<int>>v;
    vector<vector<int>>d;
    MyCalendarTwo() {
        v.clear();
        d.clear();
    }
    
    bool book(int start, int end) {
        
        bool p=true;
        
        for(int i=0;i<d.size();i++)
            if(start<d[i][1] && end>d[i][0]) return false;
        
        for(int i=0;i<v.size();i++)
            if(start<v[i][1] && end>v[i][0])
                d.push_back({max(start,v[i][0]),min(end,v[i][1])});
        
        v.push_back({start,end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */