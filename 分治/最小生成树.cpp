/*
!标签：
!题目：
给定一个 n个点的简单带权无向图 G
·每次询问一个点集S，求S关于G导出子图的最小生成树
·没有输出-1
· 2 ≤ n ≤ 10^5, 1 ≤ m, q ≤ 10^5,1 ≤ wi ≤ 10^9, ∑ ki ≤ 10^5
!题解：
1.∑ ki ≤ 10^5：涉及的总点集不超过1e5;
2.n=m=1e5;稀疏图（局部稠密）
3.稀疏：边和点数量差不多。稠密：点少边多（接近完全图）(n*(n-1)/2条边)
4.最小生成树算法时间复杂度(mlogm)与边相关
5.当涉及点少于500-1000时，建立相关子图O(n^2)。跑kruskal(此时局部可能稠密)
6.点数大的时候,直接跑原本图的kruskal,时间复杂度是:O(mlogm)
假定每次查询都是n=1000,则q=1e5/1000=100次,100*mlogm=1e7*16;
使用in优化了时间复杂度(因为只考虑在集合中的点.)
*/
#include <bits/stdc++.h>
#define ll long long
const int infmin = 0xc0c0c0c0;
const int infmax = 0x3f3f3f3f;
using namespace std;
const int maxn = 1e5 + 10;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

// 并查集(Kruskal用)
int group[maxn];
inline int findroot(int x)
{
    if (x == group[x])
        return group[x];
    return group[x] = findroot(group[x]);
}

struct edge
{
    int from, to, weight;

    bool operator<(const edge& other) const
    {
        return weight < other.weight;
    }
};
vector<edge> edgeSet;        // 总边集
map<pair<int, int>, int> mp; // 用于查找边权

int s[maxn];   // 查询点集
bool in[maxn]; // 需要处理的点(当询问规模过大时使用)

signed main()
{

    int n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        edgeSet.push_back({ u, v, w });
        mp[{u, v}] = w;
    }
    sort(edgeSet.begin(), edgeSet.end()); // 边权从小到大排序

    while (q--)
    {
        memset(in, 0, sizeof(in));
        int k = read();
        for (int i = 1; i <= k; i++)
        {
            s[i] = read();
            group[s[i]] = s[i];
            in[s[i]] = 1;
        }
        vector<edge> vec; // 本轮建立MST所用到的边集
        if (k < 500)
        {
            for (int from = 1; from <= k; from++)
            {
                for (int to = 1; to <= k; to++)
                {
                    if (mp.find({ s[from], s[to] }) != mp.end())
                        //直接mp[]!=0会超时
                    {
                        vec.push_back({ s[from], s[to], mp[{s[from], s[to]}] });
                    }
                }
            }
            sort(vec.begin(), vec.end());
        }
        else
        {
            vec = edgeSet;
        }
        // Kruskal模版
        ll res = 0, cnt = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            int a = vec[i].from, b = vec[i].to, w = vec[i].weight;
            if (in[a] && in[b])
            {
                a = findroot(a), b = findroot(b);
                if (a != b) // 如果两个连通块不连通，则将这两个连通块合并
                {
                    group[a] = b;
                    res += w;
                    cnt++;
                }
            }
        }

        if (cnt < k - 1)
            res = -1;

        printf("%lld\n", res);
    }

    return 0;
}