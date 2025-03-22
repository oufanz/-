/*
!标签：数位变换
!题目：
将l变成r，每次增加1，发生了多少次数位变换
例如：9->10 两次
10->20 11次
!题解：
按每一位考虑：当前位变换次数是当前位及之前位所组成的数。
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
int f(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x;
        x /= 10;
    }
    return ans;
}
void solve()
{
    int l, r;cin >> l >> r;
    cout << f(r) - f(l) << endl;
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