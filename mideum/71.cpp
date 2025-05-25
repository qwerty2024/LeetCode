class Solution 
{
public:
    string simplifyPath(string path) 
    {
        int n = path.size();
        stack<string> st;
        
        int i = 0;
        while (i < n)
        {
            string tmp = "";
            if (path[i] == '/')
            {
                while (i < n && path[i] == '/')
                {
                    i++;
                }
            }
            else
            {
                while (i < n && path[i] != '/')
                {
                    tmp += path[i];
                    i++;
                }

                if (tmp == ".")
                {
                    
                }
                else if (tmp == "..")
                {
                    if (!st.empty())
                        st.pop();
                }
                else
                    st.push(tmp);
            }
        }

        string ans = "";

        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans.size() == 0)
            return "/";

        return ans;
    }
};