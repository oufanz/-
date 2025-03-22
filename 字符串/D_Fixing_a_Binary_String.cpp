/*
!标签：字符串+贪心+维护当前位置能否满足条件
!题目：
https://codeforces.com/contest/1979/problem/D
任一个位置一刀两段，翻转左边那段后衔接到右边使其满足要求：
s1=s2=…=sk
si+k≠si(1≤i≤n−k)
!题解：
由于：每次交换后子需要检查后k个位置即可
而最多有n/k个位置满足条件
时间复杂度是O(n)
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#ifdef _DEBUG
#include <debug.h>
#else
#define look(...) 42
#define bug 66
#endif
const int N = 1e6 + 10, INF = 1e17;
int a[N];
bool pre[N];
bool suf[N];
int n, k;
string s;
void solve()
{
    cin >> n >> k >> s;
    if (k == n)
    {
        int cnt = count(s.begin(), s.end(), s.front());
        cout << (cnt == n ? 1 : -1) << '\n';
        return;
    }
    s = ' ' + s + ' ';
    pre[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] && (i <= k || s[i] != s[i - k]);
    }
    suf[n + 1] = 1;
    for (int i = n; i >= 0; --i)
    {
        suf[i] = suf[i + 1] && (i + k > n || s[i] != s[i + k]);
    }
    for (int i = 1, cnt = 0; i <= n; ++i)
    {
        if (s[i] != s[i - 1]) cnt = 1;
        else ++cnt;
        if (cnt >= k && s[i] != s[i + 1])
        {
            int p = i - k;
            if (!p || !pre[p] || !suf[p + 1]) continue;
            int ok = 1;
            for (int j = n - k + 1; j <= n; ++j)
            {
                int x = p - (j + k - n) + 1;
                if (x < 1) break;
                if (s[x] == s[j])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << p << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
    return;
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