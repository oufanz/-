/*
!标签：组合数+1600
!题目：
我们有一个大型的方形网格，有 H 行和 W 列。Iroha 现在站在左上角的单元格。她将重复向右或向下移动到相邻的单元格，直到她到达右下角的单元格。
然而，她不能进入底部 A 行和最左边 B 列的交集处的单元格。（即有 A×B 个禁止进入的单元格。）其他单元格没有限制。
找出她可以到达右下角单元格的路径数。
由于这个数字可能非常大，请输出这个数字对 10^9+7 取模的结果。
- 1 ≦ H, W ≦ 100,000
- 1 ≦ A < H
- 1 ≦ B < W
!题解：
1.假设左下角没有矩形：总走法个数为：C(x2−x1+y2−y1,x2−x1);
可以构造出走法序列:RDRDRRRRD
即所走步数为：x2−x1+y2−y1，其中x2-x1为选中的向下走的位置。
有矩形的情况：
（1,1）->(i,b)   (i,b+1)->(n,m);
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
const int mod = 1e9 + 7;
int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inv(int a)
{
    // 使用费马小定理求逆元
    return qmi(a, mod - 2);
}
int f[N], invf[N];

int C(int n, int m)
{
    if (n < m || m < 0 || n < 0) return 0;
    return f[n] * invf[m] % mod * invf[n - m] % mod;
}

void init()
{
    f[0] = invf[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = f[i - 1] * i % mod;
    invf[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i > 0; --i) invf[i] = invf[i + 1] * (i + 1) % mod;
}
int arr[N];
int get(int x1, int y1, int x2, int y2)
{
    return C(x2 - x1 + y2 - y1, x2 - x1);
}
void solve()
{
    init();
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = 0;
    int lst = 0;
    for (int i = 1;i <= h;i++)
    {
        if (i <= h - a)
        {
            int t1 = get(1, 1, i, b);
            int t2 = get(i, b + 1, h, w);
            ans += t1 * t2 % mod;
            lst = t1;
            ans %= mod;
        }
        else
        {
            //不用计算。
        }
    }
    cout << ans << endl;
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