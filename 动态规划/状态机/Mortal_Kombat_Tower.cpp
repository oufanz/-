/*
!标签：状态机DP
!题目：
给定一个长度为 n 的 01 数组，先后手轮流从数组开头取数，每次可以取走 1 或 2 个数。
先后手都需要最小化先手取到 1 的数量，输出这个最小值。
1 ≤ t ≤ 2 × 10^4，1 ≤ n, ∑n ≤ 2 × 10^5，a[i] ∈ {0, 1}。
!题解：
int dp[N][2];//当前位置为i，且当前位置i是被[0:先手拿走的，1:后手拿走的]的最小代价
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
int dp[N][2];//当前位置为i，且当前位置i是被[0:先手拿走的，1:后手拿走的]的最小代价
void solve()
{
    int n;cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = INF;
    }
    dp[1][0] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (i >= 3) dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
        if (i == 2) dp[i][1] = dp[i - 1][0]; //转移 
        dp[i][0] = min(dp[i - 1][1] + a[i], dp[i - 2][1] + a[i] + a[i - 1]);
    }
    cout << min(dp[n][1], dp[n][0]) << endl;
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