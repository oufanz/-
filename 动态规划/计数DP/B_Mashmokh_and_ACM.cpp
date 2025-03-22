/*
!标签：预处理+√n*n^2
!题目：
如果一个数列中，后一个数都能被前面一个数整除，那么就叫这个数列为好数列。输入n,k，求数列中最大元素不超过 n，数列长度为k的好数列的种数（对1000000007取模)
n<=2000;
!题解：
预处理2000范围内的数即可。
dp[i][j]：当前是第i位，最后一位数字是j
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
const int N = 2000 + 10, INF = 1e17;
int a[N];
const int mod = 1000000007;
vector<int>g[N];
int dp[N][N];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (i % j == 0)
            {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 1;i <= n;i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2;i <= k;i++)
    {
        for (int j = 1;j <= n;j++)//上一位填了什么;
        {
            for (auto k : g[j])
            {
                dp[i][k] += dp[i - 1][j];
                dp[i][k] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= 2000;i++)
    {
        ans += dp[k][i];
        ans %= mod;
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