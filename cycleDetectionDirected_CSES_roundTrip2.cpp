#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<bool> pathVis;
stack<int> rs;
bool dfs(int i)
{
    vis[i] = true;
    rs.push(i);
    pathVis[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (vis[adj[i][j]] == 0)
        {
            if (dfs(adj[i][j]))
            {
                return true;
            }
        }
        if (pathVis[adj[i][j]])
        {
            rs.push(adj[i][j]);
            return true;
        }
    }
    rs.pop();
    pathVis[i] = false;
    return false;
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    pathVis.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pathVis[i] = 0;
        vis[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i))
            {
                break;
            }
        }
    }
    if (rs.empty())
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> ans;
        int temp = rs.top();
        while (!rs.empty())
        {
            ans.push_back(rs.top());
            rs.pop();
            if (ans.back() == temp and ans.size() != 1)
                break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto u : ans)
        {
            cout << u << " ";
        }
    }

    return 0;
}
