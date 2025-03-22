/*
!标签：计数DP（n^2*26）+组合数学
!题目：
求长度在 1 和 K （含）之间的由大写英文字母组成的字符串中，满足以下条件的字符串的个数（模为 998244353）：

- 对于满足 1 ≤ i ≤ 26 的每个整数 i，下面的条件都成立：
    - 设 a_i 是按词典顺序排列的第 i 个大写英文字母。例如， a_1 = A， a_5 = E， a_26 = Z。
    - 字符串中 a_i 的出现次数介于 0 和 C_i 之间（含）。
-  K<=1000
-  C_i<=1000
!题解：
dp[i][j]:当前考虑到字符i，此时长度为j;当前字符i塞了k个进去。
假定现在有一个字符串长度为n，往里面塞m个字符#，请问最后能形成多少种字符串
例如：字符串为ab，塞入1个#，则可以构成a#b，ab#，#ab
最后字符串总长度是n+m;
则答案是:C(m+n,m);即从m+n个中选择m个位置放#即可，原字符串顺序不变;
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
const int N = 1e3 + 10, INF = 1e17;
const int mod = 998244353;
int a[N];
int dp[27][N];
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

void solve()
{
    init();

    int n;cin >> n;
    for (int i = 1;i <= 26;i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1;i <= 26;i++)
    {
        for (int j = 0;j <= n;j++)
        {
            for (int k = 0;k <= j && k <= a[i];k++)
            {
                //例如:
                dp[i][j] += dp[i - 1][j - k] * C(j, k);
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        ans += dp[26][i];
        ans %= mod;
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