/*
!标签：双指针/二分
!题目：
1500
https://www.luogu.com.cn/problem/CF676C
给你一个n个字符a与b组成的字符串，求至多改动k个字符后连续相同字符个数的最大值。
关键词:连续，且只含a和b
!题解：
考虑双指针区间[l,r]是一段连续相等子串。此时还剩余的修改次数是tk;
i一直右移，如果当前字符与所求字符不同，tk次数不够，则需要移动左指针l，
使得tk>0能够修改当前位置s[i];
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
int n, k;
string s;
int get(char c)
{
    int l = 1;
    int tk = k;
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        if (s[i] != c)
        {
            while (tk == 0 && l <= i)
            {
                if (s[l] != c) tk++;
                l++;
            }
            if (tk)
                tk--;
        }
        ans = max(ans, i - l + 1);
    }
    return ans;
}
void solve()
{
    cin >> n >> k >> s;
    s = '*' + s;
    cout << max(get('a'), get('b')) << endl;
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