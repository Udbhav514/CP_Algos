#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9 + 9;
const long long int BASE = 999991;

vector<long long int> hashValues;
vector<long long int> powerValues;

void computeHash(const string &s)
{
    long long int n = s.size();
    hashValues.resize(n);
    powerValues.resize(n);

    hashValues[0] = s[0];
    powerValues[0] = 1;

    for (long long int i = 1; i < n; ++i)
    {
        powerValues[i] = (powerValues[i - 1] * BASE) % MOD;
        hashValues[i] = ((hashValues[i - 1] * BASE) % MOD + s[i]) % MOD;
    }
}

long long int getSubstringHash(long long int l, long long int r)
{
    if (l == 0)
    {
        return hashValues[r];
    }
    return (hashValues[r] - (hashValues[l - 1] * powerValues[r - l + 1]) % MOD + MOD) % MOD;
}

int main()
{
    string s;
    cin >> s;
    computeHash(s);
    vector<long long int> ans;
    for (long long int i = 0; i < s.size() - 1; i++)
    {
        if (getSubstringHash(0, i) == getSubstringHash(s.size() - 1 - i, s.size() - 1))
        {
            ans.push_back(i + 1);
        }
    }
    for (long long int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
