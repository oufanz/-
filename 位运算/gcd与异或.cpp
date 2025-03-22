/*
!标签：
!题目：
给定 x， 构造 y <x 使得 gcd(x, y) =x^y
x<=1e18
如果构造不了输出-1
!题解：
只有一位不同时候
x:11001000
y:11000000
考虑此时的gcd一定为:1000(二进制)
x'=1100
y'=1100
此时gcd为本身
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
int lowbit(int x)
{
    return x & (-x);
}
void solve()
{
    int x;cin >> x;

    if (__builtin_popcountll(x) == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << x - lowbit(x) << endl;
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