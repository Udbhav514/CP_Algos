#include <bits/stdc++.h>
using namespace std;
vector<long long int> dis;
vector<pair<long long int, long long int>> adj[1001000];
class prioritize
{
public:
    bool operator()(pair<long long int, long long int> &p1, pair<long long int, long long int> &p2)
    {
        return p1.second > p2.second;
    }
};
void djiktras(long long int sc)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, prioritize> pq;
    dis[sc] = 0;
    pq.push({sc, 0});
    while (!pq.empty())
    {
        pair<long long int, long long int> fs = pq.top();
        pq.pop();
        if (dis[fs.first] < fs.second)
        {
            continue;
        }
        for (auto v : adj[fs.first])
        {
            long long int neigh = v.first;
            long long int weight = v.second;
            if (dis[neigh] > (dis[fs.first] + weight))
            {
                dis[neigh] = dis[fs.first] + weight;
                pq.push({neigh, dis[neigh]});
            }
        }
    }
}
int main()
{
    long long int n, m;
    cin >> n >> m;
    dis.resize(n + 1);
    for (long long int i = 1; i <= n; i++)
    {
        adj[i].clear();
        dis[i] = 1e18;
    }
    for (int i = 0; i < m; ++i)
    {
        long long int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    djiktras(1);
    for (long long int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}
