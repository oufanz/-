/*
!标签：
!题目：
有 n 个整数 a[1], a[2], ..., a[n]，Lee 想要将它们放进 k 个有标号的盒子，使得标号为 i 的盒子中恰有 w[i] 个数。
定义一个盒子的价值为其中最大数与最小数之和，定义一种放法的总价值为所有盒子的价值之和。Lee 希望求出总价值的最大值。
1 ≤ k ≤ n ≤ 2 * 10^5, -10^9 ≤ a[i] ≤ 10^9, ∑w[i] = n
保证 ∑n ≤ 2 * 10^5。
!题解：
1.将盒子从小到大排序
2.将每个数从大到小排序；前k个数放在最大的k个盒子
3.然后将小的数尽可能放在和盒子容量大的盒子中。
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
int b[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);

    int ans = 0;
    for (int i = n, j = 1; j <= k; i--, j++)
    {
        ans += a[i];
        if (!--b[j]) ans += a[i];
    }

    for (int i = k, j = 1; i; i--)
        if (b[i]) ans += a[j], j += b[i];

    cout << ans << endl;
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