/*
!标签：1600+思维
!题目：
https://atcoder.jp/contests/abc043/tasks/arc059_b
给定字符串 s，求区间 [l, r]，使得该子串中有一种字母出现的次数严格大于该子串长度的一半。
如果没有符合条件的子串，输出两个 -1。
!题解：
*/
#include <bits/stdc++.h>
#define int long long
#define endl endl
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
    string a;
    getline(cin, a);
    int len = a.size();
    for (int i = 0;i < len;++i)
    {
        if (a[i] == a[i + 1])
        {
            cout << i + 1 << ' ' << i + 2 << endl;
            return;
        }
        if (a[i] == a[i + 2])
        {
            cout << i + 1 << ' ' << i + 3 << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}
signed main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    for (int i = 1;i <= T;i++)
    {
        // std::cerr << "Test:" << i << endl;
        solve();
    }
    return 0;
}