/*
!标签：动态规划+前缀最小值预处理+处理一半查询一半
!题目：
https://codeforces.com/contest/1989/problem/D
有n个玩具
每个玩具有两个属性：入场票和消耗
当你的金钱大于>入场票时候，玩这个玩具需要付出对应的金钱。
1e6次查询：
当你有x金钱的时候，能玩多少次玩具。
!题解：
由于b[i]<a[i]<1e6;
即考虑当前金钱为a[i]时候的最小消耗（预处理，当前前缀最小值）
且需要预处理当前金钱为i的时候可以玩多少次玩具；
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
int a[N];
int w[N];
int f[N];
int dp[N];
//f[i]:背包容量为i时候的制作并且融化一个武器最小消耗。
//dp[i]:背包容量为i的时候可以制作并且融化多少个武器。
void solve()
{
    int n;int q;
    cin >> n;
    cin >> q;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    for (int i = 0;i <= mx;i++)
    {
        f[i] = INF;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;cin >> x;
        f[a[i]] = min(f[a[i]], a[i] - x);
    }
    for (int i = 1;i <= mx;i++)
    {
        f[i] = min(f[i], f[i - 1]);
    }
    for (int i = 0;i <= mx;i++)
    {
        if (i >= f[i])
        {
            dp[i] = dp[i - f[i]] + 1;
        }
    }
    int ans = 0;
    while (q--)
    {
        int x;cin >> x;
        if (x > mx)
        {
            int t = ceil((x - mx) * 1.0 / f[mx]);
            // look(f[mx]);
            x -= t * f[mx];
            ans += t;
        }
        look(x);
        ans += dp[x];
    }
    cout << ans * 2 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    for (int i = 1;i <= T;i++)
    {
        // std::cerr << "Test:" << i << endl;
        solve();
    }
    return 0;
}