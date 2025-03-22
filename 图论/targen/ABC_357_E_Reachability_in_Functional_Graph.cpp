/*
!标签：基环树、targen、1800
!题目：
有一个 N 个点 N 条边的有向图。每个点的出度为 1，第 i 个点有一条指向 a[i] 的有向边。若从节点 u 能走到节点 v，则称 (u,v) 为可达点对。注意 (u,u) 也是可达点对。求给定的有向图中可达点对的个数。
n<=1e5;
!题解：
首先建图，然后考虑使用 Tarjan 算法将有向图中的每一个强连通分量在新图中缩为一个点，然后剩下一个 DAG 森林。
设 f[i] 表示可以到达新图 i 点的点的数量（包含本身的结点），g[i] 表示以新图 i 点结尾的不同的路径的总数目。

那么对于每一条 j→i 的边，必然有：

f[i] = f[i] + f[j]。
dp[i] = dp[i] + f[j] × CNT[i]。
其中 CNT[i] 表示新图中 i 点在原图中对应的强连通分量中点的数目。（在targen中预处理了）

因为新的图是 DAG 森林，所以每一次从入度为 0 的结点开始转移，在拓扑排序的过程中就可以直接求出答案。
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
int n;
vector<int>g[N];
vector<int>to[N];//新的图;
int dfn[N], idx, low[N];//dfs序,u往后可以到达的最低点;
stack<int>stk;
bool in_stk[N];//是否在栈内
int Bcnt;//标记强连通分量
int Belong[N];//i属于哪个强连通分量
int Bsum[N];//当前强连通分量的属性(权值和);
int in[N];
void Targen(int u)
{
    dfn[u] = low[u] = ++idx;
    stk.push(u);
    in_stk[u] = true;
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            Targen(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stk[v])
        {
            low[u] = min(low[u], low[v]);
        }
    }
    //代表是一个强连通分量的起点:
    if (dfn[u] == low[u])
    {
        ++Bcnt;
        int p;
        do
        {
            p = stk.top();
            in_stk[p] = false;
            stk.pop();
            Belong[p] = Bcnt;
            Bsum[Bcnt]++;//统计当前强连通分量属性
        } while (p != u);
    }
}
map<int, int>mp;
void init()
{
    //初始化
    for (int i = 1;i <= n;i++)
    {
        to[i].clear();
    }
    //Targen锁点
    for (int i = 1;i <= n;i++)
    {
        if (!dfn[i]) Targen(i);
    }
    //建立新图;
    for (int u = 1;u <= n;u++)
    {
        int bu = Belong[u];
        mp[Belong[u]] = u;
        int bv;//两个点所属于的强连通分量
        for (int v : g[u])
        {
            bv = Belong[v];
            if (bu == bv) continue;
            to[bu].push_back(bv);
            in[bv]++;
        }
    }
}
/*
init();调用
g[]:原图;
vector<int>to[]:代表锁点后的图
Bcnt:1~Bcnt代表缩点后的所有点
belong[i]:原本图的i代表的连通分量
*/
int dp[N];//表示以i结尾的路径总数;
int f[N];//表示可以到达i的前驱结点个数;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i].push_back(a[i]);
        // cout << i << ' ' << a[i] << endl;
    }
    init();
    int res = 0;
    queue<int>q;
    for (int i = 1;i <= Bcnt;i++)
    {
        // look(Bsum[i]);
        if (in[i] == 0)
        {
            q.push(i);
            f[i] = Bsum[i];
            dp[i] = Bsum[i] * Bsum[i];
        }
        /*
        //初始化值：
        */
        // dp[i] = Bsum[i] * Bsum[i];

    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : to[u])//一个v可能被遍历多次，所以需要提前预处理f和dp
        {
            f[v] += f[u];
            dp[v] += f[u] * Bsum[v];
            if (--in[v] == 0)
            {
                f[v] += Bsum[v];
                dp[v] += Bsum[v] * Bsum[v];
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= Bcnt; i++)
    {
        res += dp[i];
    }
    cout << res << endl;
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