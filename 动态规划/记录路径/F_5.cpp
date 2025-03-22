/*
!标签：动态规划+记忆路径
正解是抽屉原理:该解法错误.
记忆所有可达值的路径.
!题目：
问题陈述

给定一个包含N个正整数的序列A = (A[1], A[2], ..., A[N])。确定是否存在一对序列B = (B[1], B[2], ..., B[x])，C = (C[1], C[2], ..., C[y])满足所有条件，并在存在时打印出一对这样的序列。

- 1 ≤ x, y ≤ N。
- 1 ≤ B[1] < B[2] < ... < B[x] ≤ N。
- 1 ≤ C[1] < C[2] < ... < C[y] ≤ N。
- B和C是不同的序列。
    - 在这里，当x ≠ y或存在一个整数i (1 ≤ i ≤ min(x, y))使得B[i] ≠ C[i]时，我们认为B和C是不同的。
- A[B[1]] + A[B[2]] + ... + A[B[x]] 和 A[C[1]] + A[C[2]] + ... + A[C[y]]的和对200取模相等。
N<=200;
!题解：
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
const int N = 200 * 200 + 10 + 10, INF = 1e17;
int a[N];
vector<int> vi[N];
vector<int>to[N];
vector<vector<int>>cmb[N];
const int MX = 200 * 200 + 10;
bool dp[N];
bitset<201>st[N];
int n;
void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
void solve()
{
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= 200;
        sum += a[i];
        // cout << a[i] << ' ';
        // vi[a[i]].push_back(i);
    }

    // print();
    // cout << endl;
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            if (dp[j - a[i]])
            {
                dp[j] = true;
                to[j].push_back(i);
                for (auto& comb : cmb[j - a[i]])
                {
                    auto newComb = comb;
                    newComb.push_back(i);
                    cmb[j].push_back(newComb);
                }
                if (j == a[i])
                {
                    cmb[j].push_back({ i });
                }
            }
        }
    }
    for (int target = 0; target <= sum; target++)
    {
        if (!cmb[target].empty())
        {
            for (const auto& comb : cmb[target])
            {
                for (int index : comb)
                {
                    st[target][index] = 1;
                }
            }
        }
    }
    // look(sum);
    // return;
    //最后mod200的结果是:
    // cout << 366 % 166 << endl;
    // cout << (186 + 189 + 191) % 166 << endl;
    for (int Final = 0;Final < 200;Final++)
    {
        vector<vector<int>>ans;
        for (int i = 0;i <= sum;i++)
        {
            // look(i % 200);
            if (i % 200 == Final)
            {
                for (auto& it : cmb[i])
                {
                    ans.push_back(it);
                    if (ans.size() >= 2)break;
                }
            }
        }
        if (ans.size() == 2)
        {
            cout << "Yes" << endl;
            // cout << Final << endl;
            for (auto& it : ans)
            {
                cout << it.size() << ' ';
                int tmp = 0;
                for (auto& v : it)
                {
                    tmp += a[v];
                    cout << v << ' ';
                }
                look(tmp % 200);
                cout << endl;
            }
            return;
        }
    }
    cout << "No" << endl;
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