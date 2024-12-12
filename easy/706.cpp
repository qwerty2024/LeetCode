class MyHashMap 
{
    vector<int> v;

public:
    MyHashMap() 
    {
        v.resize(1000001, -1);
    }
    
    void put(int key, int value) 
    {
        v[key] = value;
    }
    
    int get(int key) 
    {
        return (v[key] != -1) ? v[key] : -1;
    }
    
    void remove(int key) 
    {
        v[key] = -1;
    }
};