class LFUCache {
    public:
    unordered_map<int,int>mp;
    vector<pair<int,int>>s;
    int cap;
    LFUCache(int capacity) {
        mp.clear();
        s.clear();
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end() || cap==0) return -1;
        int f;
        for(auto it=s.begin();it!=s.end();it++){
            if(it->second==key){
                f=1+it->first;
                s.erase(it);
                break;
            }
        }
        s.push_back(make_pair(f,key));
        return mp[key];
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(mp.find(key)!=mp.end()){
            mp[key]=value;
            int f;
            for(auto it=s.begin();it!=s.end();it++)
            if(it->second==key){
                f=1+it->first;
                s.erase(it);
                break;
            }
            s.push_back(make_pair(f,key));
            return;
        }
        
        if(mp.size()==cap){
            int k=s.begin()->second,mini=s.begin()->first;
            auto itt=s.begin();
            for(auto it=s.begin();it!=s.end();it++)
                if(mini>it->first){
                    mini=it->first;
                    k=it->second;
                    itt=it;
                }
            
            mp.erase(k);
            s.erase(itt);
        }
         mp[key]=value;
        s.push_back(make_pair(1,key));
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */