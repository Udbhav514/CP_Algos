#include <bits/stdc++.h>
using namespace std;

const long long int MAX_N = 300002;
const long long int LOG = 19; // 2^18 is slightly more than 200,000
map<pair<long long int, long long int>, long long int> edges;
vector<vector<long long int>> par(MAX_N, vector<long long int>(LOG + 1, -1));
vector<vector<long long int>> minDist(MAX_N, vector<long long int>(LOG + 1, -1));
vector<vector<long long int>> adj;
vector<long long int> level(MAX_N, 0);
long long int n, m, q;
// i m gonna do dp and find distances from the root
void dfs(long long int node, long long int parent)
{
    level[node] = level[parent] + 1;
    par[node][0] = parent;
    minDist[node][0] = edges[{node, parent}];
    for (long long int u : adj[node])
    {
        if (u != parent)
        {
            dfs(u, node);
        }
    }
}

void buildTable()
{
    for (long long int j = 1; j <= LOG; j++)
    {
        for (long long int i = 1; i <= n; i++)
        {
            if (par[i][j - 1] != -1)
            {
                par[i][j] = par[par[i][j - 1]][j - 1];
                minDist[i][j] = min(minDist[i][j - 1], minDist[par[i][j - 1]][j - 1]);
            }
        }
    }
}

long long int liftNode(long long int x, long long int k)
{
    for (long long int i = 0; i <= LOG; i++)
    {
        if (k & (1 << i))
        {
            x = par[x][i];
        }
    }
    return x;
}
long long int findMini(long long int x, long long int k)
{
    long long int mini = 1e18;
    for (long long int i = 0; i <= LOG; i++)
    {
        if (k & (1 << i))
        {
            mini = min(mini, minDist[x][i]);
            x = par[x][i];
        }
    }
    return mini;
}
long long int lca(long long int a, long long int b)
{
    if (level[a] > level[b])
        swap(a, b);
    b = liftNode(b, level[b] - level[a]);
    if (a == b)
        return a;
    for (long long int j = LOG; j >= 0; j--)
    {
        if (par[a][j] != par[b][j])
        {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    for (long long int i = 0; i < m; i++)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[{a, b}] = c;
        edges[{b, a}] = c;
    }
    dfs(1, 0); // Assume 1 is the root
    buildTable();
    cin >> q;
    edges[{1, 0}] = 1e9;
    edges[{0, 1}] = 1e9;
    while (q--)
    {
        long long int a, b;
        cin >> a >> b;
        long long int ancestor = lca(a, b);
        // cout << level[a] + level[b] - 2 * level[ancestor] << endl;
        // have to find minimum
        cout << min(findMini(a, level[a] - level[ancestor]), findMini(b, level[b] - level[ancestor])) << endl;
    }

    return 0;
}
