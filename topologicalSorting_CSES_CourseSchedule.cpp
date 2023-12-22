#include <bits/stdc++.h>
using namespace std;
long long int n, m;
vector<vector<long long int>> adj;
vector<long long int> indegree;
vector<long long int> topo;
void kahn()
{
    priority_queue<long long int> q;
    for (long long int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(-i);
            // cout << i << " ";
        }
    }
    while (!q.empty())
    {
        long long int x = q.top();
        q.pop();
        topo.push_back(-x);
        for (auto it : adj[-x])
        {
            indegree[it] = indegree[it] - 1;
            if (indegree[it] == 0)
            {
                q.push(-it);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    adj.clear();
    adj.resize(n + 1);
    indegree.resize(n + 1);
    for (long long int i = 1; i <= n; i++)
    {
        indegree[i] = 0;
    }
    for (long long int i = 0; i < m; i++)
    {
        long long int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
        indegree[b]++;
    }
 
    kahn();
    if (topo.size() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (long long int i = 0; i < topo.size(); i++)
        {
            cout << topo[i] << " ";
        }
    }
 
    return 0;
}
