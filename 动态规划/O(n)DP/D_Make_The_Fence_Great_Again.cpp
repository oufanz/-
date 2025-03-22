/*
!标签：动态规划
!题目：
有限制的选择问题
给定一个数列，让一个位置i的数+1的花费是b[i],要求使得相邻的数不相等
n<=2e5;
!题解：
考虑到对于每个位置，至多只需要增加0，1,2。增加更多没有意义。因为有这种情况:x,x+2,x+1,x;即第一个和第四个花费太大
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
int dp[N][4];//当前位置i，操作了j下
void solve()
{
    int n;cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        for (int j = 0;j < 4;j++)dp[i][j] = INF;
    }
    for (int i = 0;i < 4;i++)
    {
        dp[1][i] = b[1] * i;
    }
    for (int i = 2;i <= n;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            for (int k = 0;k < 4;k++)
            {
                int u = a[i] + j;
                int lst = a[i - 1] + k;
                if (u != lst)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0;i < 4;i++) ans = min(ans, dp[n][i]);
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