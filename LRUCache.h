/*
    bluepp
    
    2014-06-11
    2014-12-07
    
    May the force be with me!
    
    Problem:    LRU Cache
    Source:     http://oj.leetcode.com/problems/lru-cache/
    Notes:
    Design and implement a data structure for Least Recently Used (LRU) cache. 
    It should support the following operations: get and set. 
    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 
    Solution: Hash + list.
*/

class LRUCache{
private:
    int _capacity{0};
    list<pair<int, int> > _vals;
    unordered_map<int, list<pair<int, int> >::iterator> _keys;
    
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto i = _keys.find(key);
        
        if (i == _keys.end()) return -1;
        
        int value = i->second->second;
        
        _vals.erase(i->second);
        _vals.push_front({key, value});
        _keys[key] = _vals.begin();
        
        return value;
    }
    
    void set(int key, int value)
    {
        if (!_keys.count(key))
        {
            if (_vals.size() >= _capacity)
            {
                auto oldkey = _vals.back().first;
                _vals.pop_back();
                _keys.erase(oldkey);
            }
        }
        else
        {
            auto it = _keys[key];
            _vals.erase(it);
        }
        
        _vals.push_front({key, value});
        _keys[key] = _vals.begin();
    }

};



struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
};

class LRUCache{
 
public:
   LRUCache(int capacity) : size(capacity) {
    }
    
    int get(int key){
        if (cachemap.find(key) != cachemap.end()) {
            cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
            cachemap[key] = cachelist.begin();
            return cachemap[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (cachemap.find(key) != cachemap.end()) {
            cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
            cachemap[key] = cachelist.begin();
            cachemap[key]->value = value;
        }
        else {
            if (size == cachelist.size()) {
                cachemap.erase(cachelist.back().key);
                cachelist.pop_back();
            }
            cachelist.push_front(CacheNode(key, value));
            cachemap[key] = cachelist.begin();
        }
    }
private:
    list<CacheNode> cachelist;
    unordered_map<int, list<CacheNode>::iterator> cachemap;
    int size;
};
