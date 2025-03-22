/*
!标签：数位DP+异或性质+1700
!题目：
以二进制形式给出一个整数 L，问有多少个非负整数对 (a, b) 满足：
a + b = a ⊕ b ≤ L。答案对 10^9 + 7 取模。
L<=2^1e5;
!题解：
因为小于和等于时转移方程不同
dp[i][0]考虑a+b=a^b的结果的前i位，此时小于L
dp[i][1]此时等于L
重要点:a和b的同一位不能是(1,1)因为1,1会产生进位，导致a+b!=a^b;
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
int dp[N][2];
const int mod = 1e9 + 7;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = '*' + s;
    dp[0][1] = 1;
    for (int i = 1;i <= n;i++)
    {
        dp[i][0] = dp[i - 1][0] * 3 % mod;//可以填:(1,0),(0,1)(0，0)
        if (s[i] == '1')
        {
            dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;//填(0,0)
            dp[i][1] = dp[i - 1][1] * 2 % mod;//可以填:(1,0),(0,1)
        }
        else//可以填(0,0)
        {
            dp[i][1] = dp[i - 1][1];
        }
    }
    cout << (dp[n][1] + dp[n][0]) % mod << endl;
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