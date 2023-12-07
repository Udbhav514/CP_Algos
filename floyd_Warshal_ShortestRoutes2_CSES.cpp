#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m, q;
    cin >> n >> m >> q;
    ll dis[n + 1][n + 1];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            dis[i][j] = 1e18;
            if (i == j)
            {
                dis[i][j] = 0;
            }
        }
    }
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(c, dis[a][b]);
        dis[b][a] = min(c, dis[b][a]);
    }
    /*Using Floyd Warshal Algorithm*/
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {

                if (dis[i][k] != 1e18 & dis[k][j] != 1e18)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (dis[i][j] == 1e18)
            {
                dis[i][j] = -1;
            }
        }
    }
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << dis[a][b] << endl;
    }

    return 0;
}
