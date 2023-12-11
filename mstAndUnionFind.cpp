#include <bits/stdc++.h>
using namespace std;
struct UnionFind
{
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (x != parent[x])
        {
            return parent[x] = find(parent[x]);
        }
        return x;
    }
    void merge(int x, int y)
    {
        int xroot = find(x), yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] = rank[xroot] + rank[yroot];
            }
            else
            {
                parent[xroot] = yroot;
                rank[yroot] = rank[yroot] + rank[xroot];
            }
            set_size -= 1;
        }
    }
    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int size() { return set_size; }
    void print()
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << i << " -> " << parent[i] << endl;
        }
    }
};
vector<pair<int, int>> adj[1000100];
int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<int, pair<int, int>>> edgelist;
    int mst_cost = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
        edgelist.push_back({c, {a, b}});
    }
    sort(edgelist.begin(), edgelist.end());
    for (auto v : edgelist)
    {
        int x = v.second.first;
        int y = v.second.second;
        if (uf.find(x) != uf.find(y))
        {
            mst_cost = mst_cost + v.first;
            uf.merge(x, y);
        }
    }
    cout << mst_cost << endl;

    return 0;
}
