class Solution 
{
public:
    string getEncryptedString(string s, int k) 
    {
        int n = s.size(); 
        k = k % n;

        string ans = "";
        ans = s.substr(k, n - k) + s.substr(0, k);

        return ans;
    }
};