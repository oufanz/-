/*
!标签：贪心+维护后缀和
!题目：
有一长度为n需要按顺序涂m个颜色，已经给了m个颜色规定涂的长度
请输出能否有一种方案能够涂满长度n，且保证每一个颜色都存在
!题解：
贪心的考虑：
因为后面的颜色会覆盖前面的颜色，我们不妨让第一个颜色从一开始，接下来的每一个颜色的开始位置都在上一个的后面一个
发现如果后缀的能涂的颜色长度总和不能涂满整个区间，则贪心的需要从n - suf[i] + 1涂
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#ifdef _DEBUG
#include "D:\OneDrive\VScode_project\cppDebug\debug.h"
#else
#define look(...) 42
#define bug 66
#endif
const int N = 1e6 + 10, INF = 1e17;
int a[N];
int ans[N];
int suf[N];
int dis[N];
void solve()
{
    int n, m;cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < n)
    {
        cout << -1 << endl;
        return;
    }
    suf[m + 1] = 0;
    for (int i = m;i >= 1;i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }
    for (int i = 1;i <= m;i++)
    {
        if (i + a[i] - 1 > n)
        {
            cout << -1 << endl;
            return;
        }
        //能把后面的格子涂满.
        if (i - 1 + suf[i] >= n) ans[i] = i;
        else ans[i] = n - suf[i] + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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