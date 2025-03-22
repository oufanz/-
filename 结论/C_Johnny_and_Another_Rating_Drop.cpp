/*
!标签：结论题+按位统计贡献+1400
!题目：
https://www.luogu.com.cn/problem/CF1362C
定义两个数的差异为它们在二进制下不同的位的数量（我们认为它们补充了足够的前导零）。
例如，
0101 和
1110 的差异为
3 —— 它们从高到低的第
1, 3, 4 位是不同的。
你需要求出
0, 1, 2, ..., n-1, n 中相邻的数的差异之和。
多组数据，数据组数
t ≤ 10000，
1 ≤ n ≤ 10^18
!题解：
按位考虑贡献
当 i mod 2^0 = 0 时，i 的末位与 i-1 不同，差异度加 1，所以总答案增加 ⌊n / 2^0⌋。
当 i mod 2^1 = 0 时，i 的倒数第 2 位与 i-1 不同，差异度加 1，所以总答案增加 ⌊n / 2^1⌋。
当 i mod 2^2 = 0 时，i 的倒数第 3 位与 i-1 不同，差异度加 1，所以总答案增加 ⌊n / 2^2⌋。
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
void solve()
{
    int n;cin >> n;
    int ans = 0;
    while (n)
    {
        ans += n;
        n >>= 1;
    }
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