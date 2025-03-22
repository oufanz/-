/*
https://codefun2000.com/p/P1016
有一个叫塔子哥的程序员，他正在为他的新项目编写代码。这个项目需要验证一个字符串是否为合法的括号序列。塔子哥正在编写一个函数来实现这个功能。但是他遇到了一个问题：字符串中有些字符是问号？可以代替左括号（或者右括号）。他不知道该如何处理这些问号。于是他决定询问你，给定的字符串可以代表多少种不同的合法括号序列?
很典的：合法字符串的要求: s[n]==0&&s[i]>=0
dp数组含义：当前考虑到位置i，数组总和是j(左括号为-1，右括号为1)
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
const int N = 2000 + 10, INF = 1e17;
int a[N];
int dp[N][N];
const int mod = 1e9 + 7;
int add(int x, int y)
{
    return (x += y) >= mod ? x -= mod : x;
}
//st
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = '*' + s;
    dp[1][1] = 1;
    for (int i = 2;i <= n;i++)
    {
        for (int j = 0;j <= i;j++)
        {
            if (s[i] == '?')
            {
                if (j)
                {
                    dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
                }
                dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
            }
            else if (s[i] == '(')
            {
                if (j)
                    dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j + 1];
            }
            // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    cout << dp[n][0] << endl;
}
//ed

//st
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
//ed