/*
!标签：多重背包典型题
!题目：
https://codefun2000.com/p/P1025
塔子哥拥有多种火药枪，每种火药枪的威力各不相同，且每次开火前都需要一定时间填充火药。塔子哥的火药存量有限。你的任务是帮助塔子哥在给定的时间结束之前或者火药存量耗尽之前，给予敌人最大的伤害。

限制条件：
1. 每种火药枪每次开火的威力是固定的。
2. 只有当火药剩余量不小于火药枪的消耗量时，该火药枪才能开火。
3. 填充火药之外的时间忽略不计。
4. 不同种类的火药枪可以同时开火。

输入格式：
第一行包含三个整数 N, M, T，分别表示火药枪的种类数、火药数量和攻城时间。其中，1 ≤ N, M, T ≤ 1000。
接下来的 N 行，每行包含三个整数 A, B, C，分别表示火药枪的威力、每次攻击消耗的火药量和每次攻击填充火药的时间。其中，0 ≤ A, B, C ≤ 100000。

输出格式：
输出一个整数，表示在给定的时间结束之前或者火药存量耗尽之前，塔子哥能给予敌人的最大伤害。

!题解：
由样例可以看出火药枪填充火药是同时的，且可以同时开枪，独立考虑每一把枪即可，每种火药枪在时间上的限制就是独立的。即每个物品的限制数量已经固定:t/ci;
即转换为多重背包问题。
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#ifdef _DEBUG
#include "D:\OneDrive\VScode_project\cppDebug\debug.h"
#else
#define look(...) 42
#define bug 66
#endif
const int N = 1000 + 10, INF = 1e17;
int a[N];
int dp[N][N];//考虑前i把枪，火药数量为j
int g[N][4];
//st
void solve()
{
    int n, m, t;cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1;j <= 3;j++)
        {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 0;j <= m;j++)
        {
            int mx = min(m / g[i][2], t / g[i][3]);
            for (int k = 0;k <= mx;k++)
            {
                if (j - k * g[i][2] >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * g[i][2]] + k * g[i][1]);
            }
            ans = max(ans, dp[i][j]);

        }
    }
    cout << ans << endl;
}
//ed

//st
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
//ed