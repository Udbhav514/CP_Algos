#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findMainPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findMainPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int u_u = findMainPar(u);
        int v_v = findMainPar(v);
        if (u_u == v_v)
        {
            return;
        }
        if (size[u_u] > size[v_v])
        {
            size[u_u] += size[v_v];
            parent[v_v] = u_u;
        }
        else
        {
            size[v_v] += size[u_u];
            parent[u_u] = v_v;
        }
    }
};
int main()
{
    // DisjointSet ds(7);
    // ds.unionBySize(1, 2);
}
