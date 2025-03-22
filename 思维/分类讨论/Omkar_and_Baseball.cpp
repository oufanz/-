/*
!标签：1500+次数只需要极少次(分类讨论)
!题目：
给你一个 1 到 n 的排列。

定义特殊交换为：选择一段区间 [l, r]，使得此段区间上的数交换后都不在原来的位置。

问最少多少次可以将此排列变成升序的。
!题解：
考虑到至多只需要2次操作：
如果一个区间中有数在排序后的位置上，而有一些数不在排序后的位置上。
则第一次操作将所有数都放在不在排序后的位置上。
第二次操作：全部放在排完序后所在的位置。
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
    int n;
    bool f, g;
    cin >> n;

    f = 0, g = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    for (; l <= n; l++)
        if (a[l] != l)
            break;
    for (; r; r--)
        if (a[r] != r)
            break;
    for (int i = l; i <= r; i++)
    {
        if (a[i] != i) f = 1;
        if (a[i] == i) g = 1;
    }
    if (!f) cout << "0" << endl;
    else if (g) cout << "2" << endl;
    else cout << "1" << endl;
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