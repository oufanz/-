/*
!标签：动态规划
!题目：
https://codeforces.com/contest/1969/problem/C
给你一个长度为 n 的整数数组a。
你可以执行以下操作：选择数组中的一个元素，并用其邻近元素的值替换它。
你的任务是计算在执行上述操作最多 k 次的情况下，数组的总和可能达到的最小值。
n<=2e5,j<=20;
!题解：
int dp[N][11];//当前位置为i，总共执行了j次操作;
考虑当前i为此次操作的最后一个位置，操作了k次
则状态转移方程:
dp[i][j]=dp[i-d-1][j-d]+mn*(d+1);
但是注意:i-d-1为0的时候，即前缀全部操作完成，此时需要复制dp[0][0]为0即可;
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
const int N = 3e5 + 10, INF = 1e17;
int a[N];
int dp[N][11];//当前位置为i，执行了j次操作;
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j <= k;j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    int sum = 0;
    for (int i = 1;i <= n;i++)
    {
        sum += a[i];
        dp[i][0] = min(dp[i][0], sum);
        for (int j = 0;j <= k && j <= i - 1;j++)//j:操作了多少次;
        {
            int mn = INF;
            for (int d = 0;d <= j;d++)//从之前哪个位置转移过来.
            {
                mn = min(mn, a[i - d]);
                dp[i][j] = min(dp[i][j], dp[i - d - 1][j - d] + mn * (d + 1));
            }
        }
    }
    int ans = INF;
    for (int j = 0;j <= k;j++)
    {
        ans = min(ans, dp[n][j]);
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1;i <= T;i++)
    {
        // std::cerr << "Test:" << i << endl;
        solve();
    }
    return 0;
}