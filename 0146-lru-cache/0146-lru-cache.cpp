class LRUCache {
public:
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        dq.erase(it);
        dq.push_front({key, value});
        mp[key] = dq.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dq.erase(mp[key]);
            mp.erase(key);
        }

        dq.push_front({key, value});
        mp[key] = dq.begin();

        if (dq.size() > cap) {
            int oldKey = dq.back().first;
            dq.pop_back();
            mp.erase(oldKey);
        }
    }
};