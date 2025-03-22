/*
!标签：线性DP+状态压缩结合
!题目：
给你一个包含字符A、B 和？ 的长度为 n 的字符串 s。你可以把？ 替换成A 或B，但是要保证s 中不能出现长度为 k 的回文字符串。求一共有几种可能的填涂方法，答案对998244353 取模。2≤≤1000,2≤k≤ 10
!题解：
dp[i][j]：当前考虑到第i位，最后k位的状态是j;
dp[i][j]+=dp[i-1][k];状态k和j不能是回文字符串.
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
const int mod = 998244353;
int a[N];
vector<int>vi[N];
vector<int>tmp;
string s;
int n, k;
void dfs(int sum, int u, int dep)
{
    if (dep >= k || u < 1)
    {
        tmp.push_back(sum);
        return;
    }
    if (a[u] == 1)
    {
        dfs(sum + (1ll << dep), u - 1, dep + 1);
    }
    else if (a[u] == 0)
    {
        dfs(sum, u - 1, dep + 1);
    }
    else
    {
        dfs(sum, u - 1, dep + 1);
        dfs(sum + (1ll << dep), u - 1, dep + 1);
    }
}
int dp[N][N];
std::string get(int number)
{
    std::bitset<32> binaryRepresentation(number);
    std::string binaryString = binaryRepresentation.to_string();

    // 去除前导零
    size_t firstOne = binaryString.find('1');
    if (firstOne != std::string::npos)
    {
        binaryString = binaryString.substr(firstOne);
    }
    while (binaryString.size() < k)binaryString = '0' + binaryString;
    return binaryString;
}
bool check(int x)
{
    string u = get(x);
    int l = 0, r = u.size() - 1;
    while (l < r)
    {
        if (u[l] != u[r]) return false;
        l++, r--;
    }
    return true;
}
void solve()
{
    cin >> n >> k;
    cin >> s;
    for (int i = 1;i <= n;i++)
    {
        if (s[i - 1] == 'A')a[i] = 0;
        else  if (s[i - 1] == 'B')a[i] = 1;
        else a[i] = 2;
        tmp.clear();
        dfs(0, i, 0);
        for (auto it : tmp)
        {
            vi[i].push_back(it);
        }
    }
    for (int i = 1;i <= k;i++)
    {
        for (int j = 0;j < vi[i].size();j++)
        {
            dp[i][vi[i][j]] = 1;
        }
    }
    for (int i = k + 1;i <= n;i++)
    {
        for (int j = 0;j < vi[i].size();j++)
        {
            if (check(vi[i][j])) continue;
            int& res = dp[i][vi[i][j]];
            if (a[i - k] == 1 || a[i - k] == 2)
            {
                int t = (vi[i][j] >> 1) + (1ll << (k - 1));
                if (!check(t))
                    res += dp[i - 1][t];
                res %= mod;
            }
            if (a[i - k] == 0 || a[i - k] == 2)
            {
                int t = vi[i][j] >> 1;
                if (!check(t))
                    res += dp[i - 1][t];
                res %= mod;

            }
        }
    }
    int ans = 0;
    for (int i = 0;i < vi[n].size();i++)
    {
        ans += dp[n][vi[n][i]];
        ans %= mod;
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