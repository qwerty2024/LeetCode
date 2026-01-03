class Solution 
{
public:
    string generateTag(string caption) 
    {
        int len = caption.size();
        vector<string> words;
        
        int i = 0;
        while (i < len)
        {
            string word = "";

            if ((caption[i] >= 'A' && caption[i] <= 'Z') || (caption[i] >= 'a' && caption[i] <= 'z'))
            {
                while (i < len && ((caption[i] >= 'A' && caption[i] <= 'Z') || (caption[i] >= 'a' && caption[i] <= 'z')))
                {
                    if (caption[i] >= 'A' && caption[i] <= 'Z')
                        word += (caption[i] + 32);
                    else
                        word += caption[i];
                    i++;
                }
            }

            if (word != "")
                words.push_back(word);
            
            i++;
        }

        string ans = "#";

        for (int i = 1; i < words.size(); i++)
        {
            words[i][0] -= 32;
        }

        for (const auto& a : words)
            ans += a;

        return ans.substr(0, 100);
    }
};