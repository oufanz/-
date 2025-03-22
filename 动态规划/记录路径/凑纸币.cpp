/*
!标签：记录路径
!题目：
有n个数a[i]能否恰巧凑出两份m大小的钱币，要求输出方案
注意限制条件：每一个钱币只能使用一次。即01背包需要回溯
!题解：
如果需要记录路径，则需要开辟对应类型的数组:即pre[i][j]需要记录上一个位置i和j
假设是三维的DP数组则需要pre[i][j][k]记录上一个位置i'和j'和k'


*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#ifdef _DEBUG
#include "debug.h"
#else
#define look(...) 42
#define bug 66
#endif
const int N = 2000 + 10, INF = 1e17;
#define x first
#define y second
typedef pair<int, int> pii;
bool check(pii a)
{
    if (a.first == 0 && a.second == 0)
    {
        return false;
    }
    return true;
}
void solve()
{
    int m;cin >> m;
    int n;cin >> n;
    vector<int>a(n + 1);
    vector<int>vis(n + 1);
    vector<vector<pii>>dp(n + 1, vector<pii>(m + 1));
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        dp[i][a[i]] = { i,a[i] };
    }
    if (m * 2 != sum)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 0;j <= m;j++)
        {
            //不选择：
            if (check(dp[i - 1][j]))
            {
                dp[i][j] = { i - 1,j };
            }
            //选择
            if (j - a[i] >= 0 && check(dp[i - 1][j - a[i]]))
            {
                dp[i][j] = { i - 1,j - a[i] };
            }
        }
    }
    vector<int>ans1, ans2;
    int p1 = n, p2 = m;
    // look(dp[n][m].first);
    // look(dp[n][m].second);
    // return;
    while (check(dp[p1][p2]))
    {
        int ls1 = dp[p1][p2].first;
        int ls2 = dp[p1][p2].second;
        //如果是转移的，而不是:dp[i][j]=dp[i-1][j];转移的。
        if (p1 != ls1 && p2 != ls2)
        {
            vis[p1] = true;
        }
        //如果是最后一个终点，即以当前位置就结束了。
        if (p1 == ls1 && p2 == ls2)
        {
            vis[p1] = true;
            break;
        }
        p1 = ls1;
        p2 = ls2;
    }
    sum = 0;
    for (int i = 1;i <= n;i++)
    {
        if (!vis[i])
        {
            sum += a[i];
            ans2.push_back(a[i]);
        }
        else
        {
            ans1.push_back(a[i]);
        }
    }
    look(sum);
    if (ans1.size() && ans2.size())
    {
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        if (ans1[0] > ans2[0] || (ans1[0] == ans2[0] && ans1.size() < ans2.size()))     swap(ans1, ans2);
        for (int it : ans1)cout << it << ' ';
        cout << endl;
        for (int it : ans2)cout << it << ' ';
    }
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    for (int i = 1;i <= T;i++)
    {
        solve();
    }
    return 0;
}