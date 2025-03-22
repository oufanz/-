/*
!标签：动态规划(O(n√n))+求一个数的所有因数(√n)
!题目：
给出一个长度为 n 的序列a，并令 s 为 a 的子序列，pos[i]为 s[i]在原序列里的位置,
当且仅当s[j]<s[j+1]且 pos[j+1]%pos[j]=0 时，序列s是美丽的.
你需要求出序列a的最长的美丽子序列的长度
n<=1e5;
!题解：
dp[i]:以i结尾的美丽子序列
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
int dp[N];
void solve()
{
    int n;cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        dp[i] = 1;
        vector<int>tmp;
        for (int j = 1;j * j <= i;j++)
        {
            if (i % j == 0)
            {
                tmp.push_back(j);
                if (j != i / j)
                    tmp.push_back(i / j);
            }
        }
        for (auto it : tmp)
        {
            if (it == i) continue;
            if (a[it] < a[i])
                dp[i] = max(dp[i], dp[it] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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