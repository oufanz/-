/*
!标签：图论DSU缩小点+存边DP
!题目：
https://www.luogu.com.cn/problem/AT_abc335_e
给定一个N 个点M 条无向边的图，图上每个点都有其点权。求所有经过点权单调不降的1 到n 的路径中，出现的不同点权的个数最多的一条路径上的点个数是多少。
!题解：
考虑边的类型：如果相等则需要将两个点缩为一个点
而且只连a[u]<a[v]的边
从小到大考虑边权，进行DP转移即可
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
class DSU
{
public:
    vector<int> p, sz;
public:
    DSU(int n) : p(n + 1), sz(n + 1, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void init(int n)
    {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};
#define x first
#define y second
typedef pair<int, int> pii;
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int mx = *max_element(a + 1, a + n + 1) + 1;
    vector<pii>vi[mx];
    for (int i = 1; i <= m; i++)
    {
        int u, v;cin >> u >> v;
        if (a[u] > a[v])
        {
            swap(u, v);
        }
        if (a[u] == a[v])
        {
            dsu.merge(u, v);
        }
        else
            vi[a[u]].push_back({ u,v });
    }
    vector<int>dp(n + 1, -INF);
    dp[dsu.find(1)] = 1;
    for (int i = 0;i < mx;i++)
    {
        for (auto& [u, v] : vi[i])
        {
            u = dsu.find(u);
            v = dsu.find(v);
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    cout << max(0ll, dp[dsu.find(n)]) << endl;
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