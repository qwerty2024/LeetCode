class Solution
{
public:
    string answerString(string w, int fr)
    {
        int n = w.size();
        if (fr == 1) return w;

        int max_len = n - fr + 1;
        string str = w.substr(0, max_len);
        string ans = str;
        
        for (int i = 1; i < n; ++i) 
        {
            str.erase(str.begin());
            
            if (i + max_len - 1 < n) 
                str += w[i + max_len - 1];
            
            ans = max(ans, str);
        }
        return ans;
    }
}; 