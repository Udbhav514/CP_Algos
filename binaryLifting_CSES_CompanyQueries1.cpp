#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> par(200002, vector<int>(25, -1));
int n, q;
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
    for (int i = 0; i < n - 1; i++)
    {
        cin >> par[i + 2][0];
    }
    buildTable();
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << parent(a, b) << endl;
    }

    return 0;
}
