/*
!标签：树状数组+二分+2100
!题目：
Monocarp正在玩一款电脑游戏。他开始时的等级为1。他将要依次与n个怪物战斗，怪物的等级依次为a[i]。
对于每个怪物，Monocarp的遭遇如下：
- 如果Monocarp的等级严格高于怪物的等级，怪物就会逃跑。
- 否则，Monocarp会与怪物战斗。
每当Monocarp与第k个怪物战斗后（逃跑的怪物不算），他的等级将提升1。因此，在与第k个怪物战斗后，他的等级变为2，在与第2k个怪物战斗后，等级变为3，在与第3k个怪物战斗后，等级变为4，依此类推。
你需要处理q个查询，查询的形式为：
- i x：如果参数k等于x，Monocarp会与第i个怪物战斗吗（或者这个怪物会逃跑）？
输入
第一行包含两个整数n和q（1 ≤ n, q ≤ 2 * 10^5）—— 怪物的数量和查询的数量。
第二行包含n个整数a[1], a[2], ..., a[n]（1 ≤ a[i] ≤ 2 * 10^5）—— 怪物的等级。
在接下来的q行中，每行包含两个整数i和x（1 ≤ i, x ≤ n）—— 第j个查询中怪物的索引和升级所需的战斗次数。

!题解：
由于有q个查询，预处理每个位置i：要想打到i，则需要的升级所需的战斗次数res[i];
预处理：二分答案打胜当前怪物至少升级所需的战斗次数mid，
check()：当前需要打败i位置怪物则：等级至少为:a[i]+1;由于初始等级为1，
则至少打败：a[x] * v个怪物。树状数组维护当前位置之前的：
结论：如果遇到一个怪物在升级所需的战斗次数为x时候需要战斗，则x+1时候也一定需要战斗.
快速查询一个位置在不同的k下有多少个怪物被打可以使用树状数组;
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
const int N = 2e5 + 10, INF = 1e17;
int a[N];
int tr[N], n, q;
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x;i < N;i += lowbit(i))
    {
        tr[i] += v;
    }
}
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}
int query(int l, int r)
{
    return sum(r) - sum(l - 1);
}
int s0 = 0;
//可以打该怪物.
bool check(int pos, int md)
{
    int t2 = sum(md);//能打败的怪物.

    return (1 + t2 / md) <= a[pos];
}
int qry[N];//左侧：等级高->怪物逃跑,右侧：等级低->升级(战斗)
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        tr[i] = 0;
        qry[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        int l = 1, r = 2e5;
        while (l < r)
        {
            //等级小于怪物.
            //找尽可能小的值以至于能与怪物战斗.
            int mid = (l + r) >> 1;
            //可以打，则需要更小.
            if (check(i, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        qry[i] = l;
        add(qry[i], 1);
    }
    for (int i = 1; i <= q; i++)
    {
        int pos, t;cin >> pos >> t;
        cout << ((qry[pos] <= t) ? "YES" : "NO") << endl;
    }
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