#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<bool> vis;
vector<bool> vis2;
vector<int> comps;
stack<int> s;
void dfs(int i)
{
    vis[i] = true;
    // cout << i << " ";

    for (int j = 0; j < adj[i].size(); j++)
    {
        if (vis[adj[i][j]] == 0)
        {
            dfs(adj[i][j]);
        }
    }
    s.push(i);
}
void dfs2(int i, int compNo)
{
    vis2[i] = true;
    comps[i] = compNo;
    for (int j = 0; j < adj2[i].size(); j++)
    {
        if (vis2[adj2[i][j]] == 0)
        {
            dfs2(adj2[i][j], compNo);
        }
    }
}
int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    adj2.resize(n + 1);
    comps.resize(n + 1);
    vis2.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        vis2[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    int maxi = 0;

    int compNo = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = s.top();
        s.pop();
        if (!vis2[u])
        {
            compNo++;
            dfs2(u, compNo);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        maxi = max(maxi, comps[i]);
    }
    cout << maxi << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << comps[i] << " ";
    }

    return 0;
}
