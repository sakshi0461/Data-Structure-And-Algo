class RandomizedCollection {
public:
    multiset<int>mp;
    RandomizedCollection() {
        mp.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool out=true;
        if(mp.find(val)!=mp.end()) out=false;
        mp.insert(val);
        return out;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto d=mp.find(val);
        if(d==mp.end()) return false;
        mp.erase(d);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        auto it=mp.begin();
        int ran=rand()%mp.size();
        for(int i=0;i<ran;i++,it++);
        return *it;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */