/*
!标签：中位数结论
!题目：
一共有 t 组数据，每组数据第一行为 n，为字符串长度，下一行为一个字符串（只有 ' . ' 和 ' * '字符），每次可以向右或者向左移动 ‘ * ’ 字符，求把所有的 ' * ' 字符连起来的最小移动次数。
!题解：
1.结论:向最中间的*靠拢
2.for循环方法：
对于当前选的位置 k，如果它右移一位，那么它左边的就多走一格，右面的就少走一格（包括在 k 这个位置上的）。那么，我们先求出原点的答案，再往后推进即可。
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
int num[N];
int tot;
int n;
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    tot = 0;
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '*')
        {
            num[++tot] = i + 1;
        }
    }
    if (tot == 0 || tot == 0)
    {
        cout << 0 << endl;
        return;
    }
    int mid = (tot / 2) + 1;
    for (int i = 1;i < mid;i++)
        ans += num[mid] - num[i] - (mid - i);
    for (int i = mid + 1;i <= tot;i++)
        ans += num[i] - num[mid] - (i - mid);
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