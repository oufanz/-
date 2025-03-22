/*
!标签：哈希表+牛客多校
!题目：
红色站在笛卡尔坐标系的坐标(0, 0)上。她有一串指令：上、下、左、右（其中“右”使x坐标增加1，“上”使y坐标增加1）。
现在红色想选择一个连续的指令子串并执行它们。红色希望最终执行指令时可以经过坐标(x, y)。她想知道有多少种选择方案。
输入描述:
第一行包含三个整数n, x和y(1 ≤ n ≤ 2 × 10^5, -10^5 ≤ x, y ≤ 10^5)即指令字符串的长度和红色希望经过的坐标。

第二行包含一个长度为n的字符串，由字符'W', 'S', 'A', 'D'组成，分别表示四个方向：上、下、左和右。

输出描述:
输出一个整数，表示连续子串的选择方案数。
!题解：
注意：记得清0
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
#define x first
#define y second
typedef pair<int, int> pii;
pii S[N];
void solve()
{
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    s = '*' + s;
    map<pii, int>mp;
    int ans = 0;
    mp[{0, 0}]++;
    if (x == 0 && y == 0)
    {
        for (int i = 1;i <= n;i++)
        {
            ans += (n - i + 1);
        }
        cout << ans << endl;
        return;
    }
    for (int i = 1;i <= n;i++)
    {
        S[i] = S[i - 1];
        if (s[i] == 'A')
        {
            S[i].x--;
        }
        else if (s[i] == 'D')
        {
            S[i].x++;
        }
        else if (s[i] == 'W')
        {
            S[i].y++;
        }
        else
        {
            S[i].y--;
        }
        int tx = S[i].x - x;
        int ty = S[i].y - y;
        int tt = mp[{tx, ty}];
        ans += tt * (n - i + 1);
        mp[{tx, ty}] = 0;//关键！！
        mp[{S[i]}]++;
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