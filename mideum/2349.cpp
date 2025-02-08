class NumberContainers 
{
    unordered_map<int, set<int>> um;
    unordered_map<int, int> used;

public:
    NumberContainers() 
    {
        
    }
    
    void change(int index, int number) 
    {
        if (used.contains(index))
        {
            um[used[index]].erase(index);
            
            if (um[used[index]].size() == 0)
                um.erase(used[index]);
        }

        um[number].insert(index);
        used[index] = number;        
    }
    
    int find(int number) 
    {
        if (um.contains(number))
        {
            return *(um[number].begin());
        }

        return -1;
    }
};