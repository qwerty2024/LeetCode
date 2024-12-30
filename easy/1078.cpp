class Solution 
{
public:
    vector<string> findOcurrences(string text, string first, string second) 
    {
        string s = first + " " + second + " ";
        vector<string> ans;
        int count = s.size();
        int n = text.size();
        int i = 0;

        while (true)
        {
            i = text.find(s, i);

            if (i != string::npos && i > 0 && text[i - 1] != ' ')
            {
                i++;
                continue;
            }

            if (i != string::npos)
            {
                i += count;
                cout << i << endl;
                string tmp = "";
                while (i < n && text[i] != ' ')
                {
                    tmp += text[i];
                    i++;
                }
                i -= (count + tmp.size());
                ans.push_back(tmp);
            }
            else
                break;
            
            i++;
        }

        return ans;
    }
};