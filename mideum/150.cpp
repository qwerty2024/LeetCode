class Solution 
{
    int counter(stack<string>& st)
    {
        int l = 0;
        int r = 0;
        char op = st.top()[0];

        if (st.top() == "+" || st.top() == "-" || st.top() == "*" || st.top() == "/")
        {
            op = st.top()[0];
            st.pop();
        }
        else
        {
            l = stoi(st.top());
            st.pop();
            return l;
        }

        if (st.top() == "+" || st.top() == "-" || st.top() == "*" || st.top() == "/")
        {
            r = counter(st);
        }
        else
        {
            
            r = stoi(st.top());
            st.pop();
        }

        if (st.top() == "+" || st.top() == "-" || st.top() == "*" || st.top() == "/")
        {
            l = counter(st);
        }
        else
        {
            l = stoi(st.top());
            st.pop();
        }

        switch (op)
        {
            case '+':
                return l + r;
            case '-':
                return l - r;
            case '*':
                return l * r;
            case '/':
                return l / r;
        }

        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string> st;
        for (const auto& a : tokens)
            st.push(a);

        int ans = counter(st);

        return ans;
    }
};