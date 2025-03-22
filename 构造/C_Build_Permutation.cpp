/*
!标签：序列构造+等差数列
!题目：
数组下标从0开始，构造一个长度为n的数组使得所有a[i]+i是完全平方数，要求数组是全排列（一定可以）
n<=1e5;
例如：n=7，则构造出的数列是:1 0 2 6 5 4 3，此时每个元素加上自己的下标的是完全平方数
!题解：
我们可以看见下标是等差数列，而我们也要用等差数列与它凑至一个完全平方数。
一种贪心构造的方法是对于每个完全平方数，我们尽可能多的摆放数。
正序枚举平方数会很难控制放置上界（可以大到任意平方数），所以我们考虑倒序。
每次的上界是上次最后摆放的数的下一个数，下界就是当前完全平方数减去最大的下标。
如果下界小于 0 就无解。代码实现可以使用两个指针
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
int ans[N];
vector<int>vi;
void solve()
{
    int n;cin >> n;
    unordered_map<int, bool>vis;
    int pos = lower_bound(vi.begin(), vi.end(), n) - vi.begin();
    for (int i = n - 1;i >= 0;i--)
    {
        while (vi[pos] - i >= n || vis[vi[pos] - i])
        {
            pos--;
        }
        ans[i] = vi[pos] - i;
        // for (int j = 0;j * j - i < n;j++)
        // {
        //     if (!vis[j * j - i] && j * j - i >= 0)
        //     {
        //         ans[i] = j * j - i;
        //     }
        // }
        vis[ans[i]] = true;
        // look(j * j - i);
    }
    // bug;
    for (int i = 0;i < n;i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    for (int i = 0;i * i <= 1e7;i++)
    {
        vi.push_back(i * i);
    }
    cin >> T;
    for (int i = 1;i <= T;i++)
    {
        // std::cerr << "Test:" << i << endl;
        solve();
    }
    return 0;
}