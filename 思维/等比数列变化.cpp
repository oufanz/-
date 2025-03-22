/*
!标签：
!题目：
!题解：
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
/*
差分：单点查询值：add(l,c),add(r+1,-c);
区间查询：
*/
int b[N];//差分数组
int tr1[N];//b[i]的前缀和
int tr2[N];//b[i]*i的前缀和;
int lowbit(int x)
{
    return x & -x;
}
void solve()
{
    int k = 1200;
    cout << k - lowbit(100) << endl;
    cout << ((k - lowbit(100)) ^ (k)) << endl;
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