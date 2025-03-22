/*
题目意思：找出最长的区间使得：区间所有数取模与m的值相等
取模与m可以写作: a[i]= xi * m + k;
考虑到a[i+1]-a[i]=xi*m;（k消掉了）
则：题意转换为：那么我们要找到满足条件的数组，差分后的数组一定都是 m 的倍数，换句话说差分后的 gcd 一定大于1。（因为m限制大于等于2）
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
int a[N];
//st
int st[N][20];
int Log[N];
int gcd(int a, int b)//辗转相除法
{
    if (!b) return a;
    else return gcd(b, a % b);
}
void init(int n)
{
    for (int j = 1;1 << j <= n;j++)
    {
        for (int i = 1;i <= n;i++)
        {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
}
int query(int l, int r)
{
    int k = log2(r - l + 1);
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i < n;i++)
    {
        a[i] = a[i + 1] - a[i];
        a[i] = abs(a[i]);
        st[i][0] = a[i];
    }
    init(n - 1);
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        bool flag = false;
        for (int i = 1;i < n;i++)
        {
            if (i + mid - 1 < n)
            {
                if (query(i, i + mid - 1) > 1)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l + 1 << endl;
}
//ed

//st
signed main()
{
    // Log[1] = 0;
    // for (int i = 2;i < N;i++)
    //     Log[i] = Log[i / 2] + 1;
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
//ed