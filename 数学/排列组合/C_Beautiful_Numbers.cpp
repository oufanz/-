/*
组合数学：问题转换后：
求有a个1，b个2，这些数字排列组合后能组成的数有多少个。ans = C(n,a);
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#ifdef _DEBUG
#include "D:\OneDrive\VScode_project\cppDebug\debug.h"
#else
#define look(...) 42
#define bug 66
#endif
const int N = 1e6 + 10, INF = 1e17;
const int mod = 1e9 + 7;
int a, b, n;
bool check(int x)
{
    while (x)
    {
        int u = x % 10;
        x /= 10;
        if (u != a && u != b)
        {
            return false;
        }
    }
    return true;
}
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
    cin >> a >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int sum = i * a + (n - i) * b;
        if (check(sum))
        {
            ans += C(n, i);
            ans %= mod;
        }
    }
    cout << ans << endl;
}
//ed

//
signed main()
{
    init();
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
//ed