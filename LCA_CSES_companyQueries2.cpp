#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> par(200005, vector<int>(25, -1));
vector<vector<int>> adj;
int n, q;
vector<int> level(200002, -1);
void dfs(int node, int par)
{
    level[node] = 1 + level[par];
    for (auto u : adj[node])
    {
        if (u != par)
        {
            dfs(u, node);
        }
    }
}
void buildTable()
{
    for (int j = 1; j < 25; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int between = par[i][j - 1];
            if (between != -1)
            {
                par[i][j] = par[between][j - 1];
            }
        }
    }
}
int parent(int x, int k)
{
    for (int i = 0; i < 25; i++)
    {
        if ((k & (1 << i)) && x != -1)
        {
            x = par[x][i];
        }
    }
    return x;
}
int main()
{
    cin >> n >> q;
    adj.resize(n + 2);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> par[i + 2][0];
        adj[i + 2].push_back(par[i + 2][0]);
        adj[par[i + 2][0]].push_back(i + 2);
    }

    buildTable();
    dfs(1, 0);
    // cout << q << endl;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (level[a] > level[b])
        {
            a = parent(a, level[a] - level[b]);
        }
        if (level[b] > level[a])
        {
            b = parent(b, level[b] - level[a]);
        }
        if (a == b)
        {
            cout << a << endl;
        }
        else
        {
            // we will find the imediate child of LCA
            for (int i = 24; i >= 0; i--)
            {
                if (par[a][i] != par[b][i])
                {
                    a = par[a][i];
                    b = par[b][i];
                }
            }
            cout << par[a][0] << endl;
        }
    }

    return 0;
}
