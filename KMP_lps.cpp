#include <bits/stdc++.h>
using namespace std;
vector<int> prefix(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }

        if (s[j] == s[i])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
int main()
{
    string s = "na";
    string t = "apnacollege";
    vector<int> po = prefix(s);
    for (int i = 0; i < po.size(); i++)
    {
        cout << po[i] << " ";
    }
    int i = 0;
    int j = 0;
    int ans = -1;
    while (i < t.size())
    {
        if (s[j] == t[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = po[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == s.size())
        {
            ans = i - s.size();
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
