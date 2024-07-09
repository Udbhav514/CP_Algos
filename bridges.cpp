#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> in;
vector<int> mini;
vector<int> vis;
int times = 0;
vector<pair<int, int>> ans;

void dfs(int node, int parent)
{
    in[node] = times;
    mini[node] = times;
    vis[node] = 1;
    times++;
    for (auto it : adj[node])
    {
        if (it == parent)
        {
            // do nothing
        }
        else
        {
            if (!vis[it])
            {
                dfs(it, node);
                mini[node] = min(mini[node], mini[it]);
                if (in[node] < mini[it])
                {
                    ans.push_back({min(node, it), max(node, it)});
                }
            }
            else
            {
                mini[node] = min(mini[node], mini[it]);
            }
        }
    }
}

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        cin >> n >> m;

        // Initialize global variables for each test case
        adj.clear();
        adj.resize(n + 1);
        in.clear();
        in.resize(n + 1);
        mini.clear();
        mini.resize(n + 1);
        vis.clear();
        vis.resize(n + 1);
        ans.clear();
        times = 0;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1, -1);

        sort(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for (auto p : ans)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}
