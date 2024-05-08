#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200001;
const int LOG = 18;

vector<int> adj[MAX_N];
int par[MAX_N][LOG + 1];
int level[MAX_N];
int n, q;

void dfs(int node, int parent)
{
    level[node] = level[parent] + 1;
    par[node][0] = parent;
    for (int neighbor : adj[node])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, node);
        }
    }
}

void buildTable()
{
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (par[i][j - 1] != -1)
            {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
}

int parent(int x, int k)
{
    for (int i = 0; i <= LOG; i++)
    {
        if (k & (1 << i))
        {
            x = par[x][i];
        }
    }
    return x;
}

int lca(int a, int b)
{
    if (level[a] < level[b])
    {
        swap(a, b);
    }
    a = parent(a, level[a] - level[b]);
    if (a == b)
    {
        return a;
    }

    int lo = 0, hi = level[a], ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (parent(a, mid) == parent(b, mid))
        {
            ans = parent(a, mid);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> q;
    adj[1].push_back(0);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        par[i][0] = p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    memset(par, -1, sizeof par);
    level[0] = -1;
    dfs(1, 0);
    buildTable();

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}
