class RandomizedSet 
{
    unordered_set<int> data;

public:
    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        if (data.contains(val))
        {
            return false;
        }
        else
        {
            data.insert(val);
            return true;
        }
    }
    
    bool remove(int val) 
    {
        if (data.contains(val))
        {
            data.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int getRandom() 
    {
        int offset = rand() % data.size();

        auto it = data.begin();
        advance(it, offset);

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */