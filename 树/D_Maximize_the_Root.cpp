/*
!标签：1500+DFS维护(自底向上)
!题目：
给定一颗根树，这棵树有n个顶点。树中的顶点从1到n编号，根是顶点1。a[i]的值写在第i个顶点上。

你可以执行以下操作任意次（可能是零次）：选择一个顶点v，它至少有一个子节点；将a[v]增加1；并对顶点v的子树中的所有顶点u（除了v本身）进行操作，将a[u]减少1。然而，在每次操作之后，所有顶点上的值都应为非负值。

你的任务是使用上述操作计算写在根上的最大可能值。
!题解：
记录当前子树的最小值(dp[u]);当前子树的最小值为该子树能操作最大次数。
如果子树的最小值比当前顶点的值大，则可以对当前顶点操作，使得整个子树的最小值更大(平均分)
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
vector<int>g[N];
bool vis[N];
int dp[N];
void dfs(int u, int fa)
{
    vis[u] = true;
    int flag = false;
    for (int v : g[u])
    {
        if (vis[v])
            continue;
        flag = true;
        dfs(v, u);
        dp[u] = min(dp[u], dp[v]);
    }
    if (!flag)
        dp[u] = a[u];
    else if (u == 1) dp[u] += a[u];
    else if (dp[u] > a[u])
    {
        dp[u] = (a[u] + dp[u]) / 2;
    }
}
void solve()
{
    int n;cin >> n;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INF;
        g[i].clear();
        vis[i] = false;
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int x;cin >> x;
        g[x].push_back(i);
        cout << x << ' ' << i << endl;
    }

    dfs(1, -1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << dp[1] << endl;
    // cout << "*" << endl;
    // int l = 0, r = 1e9;
    // while (l < r)
    // {
    //     int mid = (l + r + 1) >> 1;
    //     if (check(mid))
    //     {
    //         l = mid;
    //     }
    //     else
    //     {
    //         r = mid - 1;
    //     }
    // }
    // cout << l << endl;

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