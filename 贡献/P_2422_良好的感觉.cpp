/*
!标签：贡献+单调栈
!题目：P2422 良好的感觉
!题解：
注意：单调栈可以维护的是：当前位置左侧第一个小于、大于……当前数的位置
两次单调栈即可求出当前数作为最差的数可以影响的范围。
注意：单调栈弹出队列是while循环。
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
int s[N];
int l[N];
int r[N];
//求出当前位置左侧第一个小于当前数的位置。则需要将大于当前数的都弹出去。
#define x first
#define y second
typedef pair<int, int> pii;
void solve()
{
    int n;cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    stack<pii>st;
    for (int i = 1;i <= n;i++)
    {
        while (!st.empty() && st.top().first >= a[i]) st.pop();
        if (st.empty()) l[i] = 1;
        else l[i] = st.top().second + 1;
        st.push({ a[i],i });
    }
    while (!st.empty())st.pop();
    for (int i = n;i >= 1;i--)
    {
        while (!st.empty() && st.top().first >= a[i]) st.pop();
        if (st.empty()) r[i] = n;
        else r[i] = st.top().second - 1;
        st.push({ a[i],i });
    }
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        // std::cerr << l[i] << ' ' << r[i] << endl;
        ans = max(ans, a[i] * (s[r[i]] - s[l[i] - 1]));
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