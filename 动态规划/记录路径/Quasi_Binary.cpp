/*
!标签：动态规划记录容器路径！！
!题目：
https://www.luogu.com.cn/problem/CF538B
题目描述
给出一个数 n，你需要将 n 写成若干个数的和，其中每个数的十进制表示中仅包含 0 和 1。
问最少需要多少个数。
1 ≤ n ≤ 10^6
!题解：
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
vector<int>vi;
vector<int>g[N];
int dp[N];
void dfs(int u)
{
    if (u > 1e6)return;
    vi.push_back(u);
    g[u].push_back(u);
    dp[u] = 1;
    dfs(u * 10);
    dfs(u * 10 + 1);
}
void solve()
{
    memset(dp, 0x3f, sizeof dp);
    dfs(1);
    sort(vi.begin(), vi.end(), greater<int>());
    int n;cin >> n;
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j < vi.size();j++)
        {
            if (i - vi[j] >= 0)
            {
                if (dp[i] > dp[i - vi[j]] + 1)
                {
                    dp[i] = min(dp[i], dp[i - vi[j]] + 1);
                    g[i] = g[i - vi[j]];
                    g[i].push_back(vi[j]);
                }
            }
        }
    }
    cout << dp[n] << endl;
    for (auto it : g[n])cout << it << ' ';
    // vector<int>ans;
    // for (int i = 0;i < vi.size();i++)
    // {
    //     while (n - vi[i] >= 0)
    //     {
    //         n -= vi[i];
    //         ans.push_back(vi[i]);
    //     }
    // }
    // cout << ans.size() << endl;
    // for (auto it : ans)cout << it << ' ';

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