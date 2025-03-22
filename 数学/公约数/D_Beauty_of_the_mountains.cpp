/*
!标签：最大公约数
!题目：
已知有n个数
问能否使得c1*a[1]+c2*a[2]+c3*a[3]……+c4*a[n]=m;
其中 a[i] 是给定的数，c[i] 是未知数，是否有一组 c[i] 使得等式成立。
!题解：
结论：如果m%__gcd(a[1->n])则成立
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
const int N = 500 + 10, INF = 1e17;
int a[N][N];
int  s[1010][1010];
//查询
int query(int x1, int y1, int x2, int y2)
{
    return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int s1 = 0;
    int s0 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            char c;cin >> c;
            if (c == '1')
                s1 += a[i][j];
            else
                s0 += a[i][j];
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + (c == '1');
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x = i + k - 1;
            int y = j + k - 1;
            if (x <= n && y <= m)
            {
                int all = k * k;
                int u = query(i, j, x, y);
                int tmp = abs(-all + u + u);
                // vi.push_back();
                res = gcd(res, tmp);
            }
        }
    }
    // look(vi);
    // look(s1);
    // look(s0);
    int tmp = abs(s1 - s0);
    if (tmp == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (res == 0)
    {
        cout << "NO" << endl;return;
    }
    if (tmp % res == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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