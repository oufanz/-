/*
!标签：线段排序+1300
!题目：
### 问题陈述
有N个岛屿从西到东排列，由N-1座桥梁连接。
第i座桥梁连接从西边数第i个岛屿和从西边数第(i+1)个岛屿。
有一天，岛屿之间发生了一些争端，岛民提出了M个请求：
请求i：从西边数第a[i]个岛屿和从西边数第b[i]个岛屿之间发生了争端。请使这两个岛屿之间的桥梁通行不可能。
你决定拆除一些桥梁以满足所有这些M个请求。
找出必须拆除的最少桥梁数量。
### 约束条件
- 输入中的所有值都是整数。
- 2 <= N <= 10^5
- 1 <= M <= 10^5
- 1 <= a[i] < b[i] <= N
- 所有对(a[i], b[i])都是不同的。
!题解：
核心：重叠区间:ans++;
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
#define x first
#define y second
typedef pair<int, int> pii;
pii a[N];
void solve()
{
    int n, m;cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + m + 1);
    int l = a[1].x;
    int r = a[1].y;
    int ans = 1;
    for (int i = 2;i <= m;i++)
    {
        if (a[i].x < r)
        {
            look(r);
            r = min(a[i].y, r);
        }
        else
        {
            r = a[i].y;
            ans++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    for (int i = 1;i <= T;i++)
    {
        // std::cerr << "Test:" << i << endl;
        solve();
    }
    return 0;
}