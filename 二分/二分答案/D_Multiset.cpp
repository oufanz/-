/*
!标签：二分答案
!题目：
CF1354D
你需要维护一个可重集。初始时里面有 n 个正整数 {A[1], A[2], ⋯ A[n]}，它们的值域为 [1, n]。现在有 q 个操作，共有两类：
1. 若 k 为负数，则删除排名为 |k| 的数字。若不存在排名为 |k| 的数字，则忽略这次操作。
2. 若 k 为正数，则加入数字 k，满足 k ∈ [1, n]。
n, q ≤ 1×10^6 。
最后输出任意一个数列中存在的数字即可。
!题解：
二分最小的值，判断是否最后剩下一个元素<=x;
则维护>x的元素有多少个，维护<=x的元素有多少个.
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#ifdef _DEBUG
#include "debug.h"
#else
#define look(...) 42
#define bug 66
#endif

const int N = 1e6 + 10, INF = 1e17;
int a[N], b[N];
int n, q;

bool check(int x)
{
    int lsiz = 0, rsiz = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] <= x)
        {
            ++lsiz;
        }
        else
        {
            ++rsiz;
        }
    for (int i = 1; i <= q; ++i)
    {
        if (b[i] < 0)
        {
            if (-b[i] <= lsiz) --lsiz;
            else --rsiz;
        }
        else
        {
            if (b[i] <= x) ++lsiz;
            else ++rsiz;
        }
    }
    return lsiz > 0;
}

void solve()
{
    cin >> n >> q;
    int rem = n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= q; ++i)
    {
        cin >> b[i];
        if (b[i] < 0) --rem;
        else ++rem;
    }

    if (rem <= 0)
    {
        cout << 0 << endl;
        return;
    }

    int l = 1, r = n, mid, mp = n;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            if (mp > mid) mp = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << mp << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}
