class Solution
{
    struct tdii
    {
        double f;
        int s;
        int t;

        tdii(double _f, int _s, int _t) : f(_f), s(_s), t(_t) {}
    };

    struct Cmp
    {
        bool operator() (const tdii& a, const tdii& b)
        {
            return (a.f - (double)(a.s + 1) / (a.t + 1)) > (b.f - (double)(b.s + 1) / (b.t + 1));
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& c, int ex)
    {
        priority_queue<tdii, vector<tdii>, Cmp> pq;

        for (auto a : c)
        {
            tdii tmp((double)a[0] / a[1], a[0], a[1]);
            pq.push(tmp);
        }

        //while (!pq.empty())
        //{
        //    cout << pq.top().f << " " << pq.top().s << " " << pq.top().t << endl;
        //    pq.pop();
        //}

        for (int i = 0; i < ex; i++)
        {
            tdii tmp = pq.top();
            pq.pop();

            tmp.s++;
            tmp.t++;
            tmp.f = (double)tmp.s / tmp.t;

            pq.push(tmp);
        }

        double avg = 0;
        int n = pq.size();

        while (!pq.empty())
        {
            avg += pq.top().f;
            pq.pop();
        }

        return avg / n;
    }
};