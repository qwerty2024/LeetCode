class Solution 
{
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) 
    {
        //sort(sh.begin(), sh.end());

        int n = s.size();
        int curr = 0;
        vector<int> sm(n, 0);
 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq2;

        for(auto a : sh)
        {
            pq1.push({a[0], (a[2] == 1) ? 1 : -1});
            pq2.push({a[1] + 1, (a[2] == 1) ? -1 : 1});
        }

        //while (!pq2.empty())
        //{
        //    cout << pq2.top().first << " " << pq2.top().second << endl;
        //    pq2.pop();
        //}        

        for (int i = 0; i < n; i++)
        {
            while (!pq1.empty())
            {
                if (pq1.top().first == i)
                {
                    curr += pq1.top().second;
                    pq1.pop();
                }
                else
                    break;
            }

            while (!pq2.empty())
            {
                if (pq2.top().first == i)
                {
                    curr += pq2.top().second;
                    pq2.pop();
                }
                else
                    break;
            }

            sm[i] = curr;
        }

        for (int i = 0; i < n; i++)
        {
            char ch = s[i] - 'a';
            ch += (sm[i] % 26);
//cout << sm[i] << " " << endl;
            if (ch > 25)
                ch %= 26;
            else if (ch < 0)
                ch = 26 + ch;

            s[i] = ch + 'a';
        }


        return s;
    }
};