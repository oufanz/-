/*
!标签：四维区间DP+记忆化搜索
!题目：
https://www.luogu.com.cn/problem/CF149D
给出一个配对的括号序列（如 “(())()”、“()” 等，“)()”、“(()”是不符合要求的），对该序列按照以下方法染色。

一个括号可以染成红色、蓝色或者不染色。
一对匹配的括号需要且只能将其中一个染色。
相邻两个括号颜色不能相同（但都可以不染色）。
求符合条件的染色方案数，对 1000000007 取模。
s<=700;n^3复杂度 :区间DP
区间DP最好使用记忆化搜索:
!题解：
分成两种情况:
1.
(……)
2.
（……）……*
3.*……(……)
注意最后的答案是所有的，并不一定最后左右两个括号是匹配的。
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
int dp[710][710][3][3];
int match[710];
const int mod = 1e9 + 7;
bool check(int cl, int cr)
{
    if (cl > cr) swap(cl, cr);
    if (cl != 0)return false;
    if (cr == 0)return false;
    return true;
}
string s;
int dfs(int l, int r, int cl, int cr)
{
    if (r < l)return 0;
    int& res = dp[l][r][cl][cr];
    if (res != -1)return res;
    dp[l][r][cl][cr] = 0;//!访问过就需要赋为空
    if (r - l == 1)
    {
        if (check(cl, cr) && match[l] == r)
        {
            return res = 1;
        }
    }
    else if (match[l] == r && check(cl, cr))
    {

        for (int i = 0;i <= 2;i++)
        {
            for (int j = 0;j <= 2;j++)
            {
                if ((i == 0 || cl == 0 || cl != i) && (j == 0 || cr == 0 || cr != j))
                {
                    res += dfs(l + 1, r - 1, i, j);
                    res %= mod;
                }
            }
        }
    }
    else if (match[l] < r)
    {
        int mi1 = match[l];
        int mi2 = match[l] + 1;
        for (int i = 0;i <= 2;i++)
        {
            for (int j = 0;j <= 2;j++)
            {
                if ((i != j || i == 0 || j == 0) && check(cl, i))
                {
                    res += dfs(l, mi1, cl, i) * dfs(mi2, r, j, cr);
                    res %= mod;
                }
            }
        }
    }
    else if (match[r] > l)
    {
        int mi2 = match[r];
        int mi1 = mi2 - 1;
        for (int i = 0;i <= 2;i++)
        {
            for (int j = 0;j <= 2;j++)
            {
                if ((i != j || i == 0 || j == 0) && check(cr, j))
                {
                    res += dfs(l, mi1, cl, i) * dfs(mi2, r, j, cr);
                }
            }
        }
    }
    return res;

}
void solve()
{
    cin >> s;
    int n = s.size();
    s = '*' + s;
    stack<int>st;
    memset(dp, -1, sizeof dp);
    for (int i = 1;i <= n;i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            match[st.top()] = i;
            match[i] = st.top();
            st.pop();
        }
    }
    int ans = 0;
    for (int i = 0;i <= 2;i++)
    {
        for (int j = 0;j <= 2;j++)
        {
            ans += dfs(1, n, i, j);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return;
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