#include <bits/stdc++.h>
using namespace std;
long long int left(long long int index)
{
    return 2 * index;
}
long long int right(long long int index)
{
    return 2 * index + 1;
}
long long int merge(long long int left, long long int right)
{
    return min(right, left);
}
void build(long long int start, long long int end, long long int index, vector<long long int> &SGT, vector<long long int> &arr)
{
    if (start == end)
    {
        SGT[index] = arr[start];
        return;
    }
    long long int mid = (start + end) / 2;
    build(start, mid, left(index), SGT, arr);
    build(mid + 1, end, right(index), SGT, arr);
    SGT[index] = merge(SGT[left(index)], SGT[right(index)]);
}

void update(long long int start, long long int end, long long int index, vector<long long int> &SGT, long long int pos, long long int val)
{
    if (start == end)
    {
        SGT[index] = val;
        return;
    }
    long long int mid = (start + end) / 2;
    if (pos <= mid)
    {
        update(start, mid, left(index), SGT, pos, val);
    }
    else
    {
        update(mid + 1, end, right(index), SGT, pos, val);
    }
    SGT[index] = merge(SGT[left(index)], SGT[right(index)]);
}
long long int default_value()
{
    return 1e18;
}
long long int query(long long int start, long long int end, long long int index, vector<long long int> &SGT, long long int l, long long int r)
{
    // complete
    //  l...start....end....r
    if (l <= start && end <= r)
    {
        return SGT[index];
    }
    // disjolong long int
    // start end..l..r
    // l..r...start..end
    if (r < start || l > end)
    {
        return default_value();
    }
    // else partial
    long long int mid = (start + end) / 2;
    long long int leftAns = query(start, mid, left(index), SGT, l, r);
    long long int rightAns = query(mid + 1, end, right(index), SGT, l, r);
    return merge(leftAns, rightAns);
}

int main()
{
    long long int n, q;
    cin >> n >> q;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long int> SGT(4 * n + 1);
    build(0, n - 1, 1, SGT, arr);
    // 2 is sum
    // 1 is update
    for (long long int i = 0; i < q; i++)
    {
        long long int type;
        cin >> type;
        if (type == 2)
        {
            long long int l, r;
            cin >> l >> r;
            cout << query(0, n - 1, 1, SGT, l, r - 1) << endl;
        }
        else
        {
            long long int pos, val;
            cin >> pos >> val;
            update(0, n - 1, 1, SGT, pos, val);
        }
    }

    return 0;
}
