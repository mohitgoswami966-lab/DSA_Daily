
class LRUCache {
public:
    unordered_map<int, int> mp;
    vector<int> keys, values, prev, next;
    int cap, head, tail, cnt;

    LRUCache(int capacity) {
        cap = capacity;
        head = tail = -1;
        cnt = 0;
    }

    void removeNode(int i) {
        if (prev[i] != -1)
            next[prev[i]] = next[i];
        else
            head = next[i];

        if (next[i] != -1)
            prev[next[i]] = prev[i];
        else
            tail = prev[i];
    }

    void addFront(int i) {
        prev[i] = -1;
        next[i] = head;

        if (head != -1)
            prev[head] = i;
        else
            tail = i;

        head = i;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        int i = mp[key];
        removeNode(i);
        addFront(i);

        return values[i];
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            int i = mp[key];
            values[i] = value;
            removeNode(i);
            addFront(i);
            return;
        }

        if (cnt == cap) {
            int oldKey = keys[tail];
            mp.erase(oldKey);
            removeNode(tail);
            cnt--;
        }

        int i = keys.size();
        keys.push_back(key);
        values.push_back(value);
        prev.push_back(-1);
        next.push_back(-1);

        mp[key] = i;
        addFront(i);
        cnt++;
    }
};
