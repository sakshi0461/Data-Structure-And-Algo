class LRUCache {
public:
    int cap;
    unordered_map<int,int>mp;
    list<int>q;
    LRUCache(int capacity) {
        mp.clear();
        q.clear();
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        for(auto it=q.begin();it!=q.end();it++){
                if(*it==key){
                    q.erase(it);
                    break;
                }
            }
            q.push_back(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]=value;
            for(auto it=q.begin();it!=q.end();it++){
                if(*it==key){
                    q.erase(it);
                    break;
                }
            }
            q.push_back(key);
        }
        else{
            if(mp.size()==cap){
                mp.erase(q.front());
                q.pop_front();
            }
            mp[key]=value;
            q.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */