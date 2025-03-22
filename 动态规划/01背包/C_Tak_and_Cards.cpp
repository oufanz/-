/*
!标签：1600+计数型01背包
!题目：
Tak 有 N 张卡片。在第 i 张 (1 ≤ i ≤ N) 卡片上写着一个整数 x[i]。他正在从这 N 张卡片中选择一张或多张卡片，使得所选卡片上的整数的平均值恰好为 A。请问他有多少种选择方式？
- 1 ≤ N ≤ 50
- 1 ≤ A ≤ 50
- 1 ≤ x[i] ≤ 50
- N、A、x[i] 都是整数。
!题解：
1. 说到组合问题，通常是动态规划（DP）或数学方法
dp[i][j][k] = 前i张卡片中选择j张且总和为k的组合数
不选当前卡片 dp[i + 1][j][k] += dp[i][j][k]
选择当前卡片 dp[i + 1][j + 1][k + x[i]] += dp[i][j][k]
由于必须选择数量大于0则枚举i:1->n
最后只需要求dp[N][i][i*A]的总和作为答案
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
int dp[51][51][2501];
void solve()
{
    int n, k;cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0;j <= n;j++)
        {
            for (int k = 0;k < 2501;k++)
            {
                //不选择:
                dp[i][j][k] += dp[i - 1][j][k];
                if (i > 0 && j > 0 && k - a[i] >= 0)
                    //选择
                    dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
            }
        }
    }
    int ans = 0;
    for (int j = 1;j <= n;j++)
    {
        ans += dp[n][j][j * k];
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