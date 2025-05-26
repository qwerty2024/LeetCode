class MinStack 
{
    int min_current = INT_MAX;
    stack<pair<int, int>> st;

public:
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        min_current = min(min_current, val);
        st.push({val, min_current});
    }
    
    void pop() 
    {
        st.pop();
        if (!st.empty())
            min_current = st.top().second;
        else
            min_current = INT_MAX;
    }
    
    int top() 
    {
        return st.top().first;
    }
    
    int getMin() 
    {
        return st.top().second;
    }
};