#include <bits/stdc++.h>
using namespace std;
 
const long long int INF = 1e17;
const long long int NINF = INF * (-1);
 
struct triplet
{
    long long int first;
    long long int second;
    long long int third;
};
 
long long int n, m;
vector<triplet> edges;
vector<long long int> dist;
 
void bellman_ford()
{
    for (long long int i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            long long int u = e.first;
            long long int v = e.second;
            long long int d = e.third;
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], d + dist[u]);
            dist[v] = max(dist[v], NINF);
        }
    } // n relaxations
 
    for (long long int i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            long long int u = e.first;
            long long int v = e.second;
            long long int d = e.third;
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + d < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }
}
 
int main()
{
    cin >> n >> m;
    dist.resize(n + 1);
    edges.resize(m);
    for (long long int i = 0; i < m; ++i)
    {
        struct triplet inp;
        cin >> inp.first >> inp.second >> inp.third;
        inp.third *= -1;
        edges[i] = inp;
    }
    if (n == 1)
    {
        if (edges[0].third <= 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
 
        for (long long int i = 2; i <= n; ++i)
        {
            dist[i] = INF;
        }
 
        bellman_ford();
        if (dist[n] == NINF)
        {
            if (n == 1)
            {
                cout << -1;
            }
 
            cout << -1 << endl;
            return 0;
        }
        if (n == 1)
        {
            cout << -1;
        }
        else
        {
            cout << dist[n] * (-1) << endl;
        }
    }
