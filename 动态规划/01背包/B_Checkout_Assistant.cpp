/*
!标签：DP+01背包变形
!题目：
https://codeforces.com/problemset/problem/19/B
Bob 来到一家现购自运商店，将 n 件商品放入了他的手推车，然后到收银台付款。每件商品由它的价格 ci和收银员扫描它的时间ti秒定义。
当收银员正在扫描某件商品时，Bob 可以从他的手推车中偷走某些其它商品。Bob 需要恰好 1 秒来偷走一件商品。Bob 需要付给收银员的最少钱数是多少？请记住，收银员扫描商品的顺序由 Bob 决定。
n<=2000
!题解：
01背包的变形
目标：获得至少n个物品
由于买i物品时候，可以花费ci获得ti+1个物品
则DP数组：dp[i][j]:考虑前i个物品，可以买到最多j个物品的最小价值。
ans:dp[n][n];
注意最大体积是max(t[i]+n);考虑到体积的值域。
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
int b[N];
int dp[2001][4010];
void solve()
{
    int n;cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        //a[i]:物品，b[i]:金钱
        cin >> a[i] >> b[i];
        a[i]++;
    }
    for (int i = 1;i <= n;i++)
    {
        dp[i][a[i]] = min(dp[i][a[i]], b[i]);
        for (int j = 0;j < 4010;j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            if (j - a[i] >= 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
        }
    }
    int ans = INF;
    for (int i = n;i < 4010;i++)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
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