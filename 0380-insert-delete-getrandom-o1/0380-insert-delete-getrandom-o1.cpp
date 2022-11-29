class RandomizedSet {
public:
    unordered_map<int, bool>meri_marzi;
    int n;
    RandomizedSet() {
        n = 0;
    }
    
    bool insert(int val) {
        if(meri_marzi.find(val) == meri_marzi.end()) {
            n++;
            meri_marzi[val] = true;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(meri_marzi.find(val) != meri_marzi.end()) {
            n--;
            // meri_marzi[val]--;
            meri_marzi.erase(val);
            return true;
        }
        return false;
    }
    // Quora (getting a random element form set) IMP NEW
    /*
    To get a random element from a set first take a random number using rand() function then take a modulas (%) by set size so that our iterator will not go out of bounds. Now, to get random element just iterate idx=rand() % s.size() times to get random element.
    */
    int getRandom() {
        auto it = meri_marzi.begin();
        int t = rand() % n;
        while(t--) {
            it++;
        }
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */