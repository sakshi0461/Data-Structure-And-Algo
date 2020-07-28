class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<vector<int>>v;
    MyHashMap() {
        v.clear();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
       for(int i=0;i<v.size();i++)
               if(v[i][0]==key){
                   v[i][1]=value;
                   return;
               }
        v.push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(int i=0;i<v.size();i++)
            if(v[i][0]==key)
                return v[i][1];
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index=-1;
        for(int i=0;i<v.size();i++)
            if(v[i][0]==key){
                index=i;
                break;
            }
        if(index!=-1){
            swap(v[index],v[v.size()-1]);
            v.pop_back();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */