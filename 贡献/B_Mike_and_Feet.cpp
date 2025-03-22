/*
!标签：贡献+单调栈
!题目：
给你一个序列，求出对于每个长度为 x的区间最小值 的最大值。
!题解：
一个数x最大能在len的长度取得最小值，(单调栈使得这个数尽量的大)
1.l[i]当前位置i之前满足小于a[i]的最左边界,r[i]同理
2.a[i]是区间长度r[i]-l[i]+1最大的数（需要在长度r[i]-l[i]+1中取max），依次把每个数的贡献算出来
3.如果一个数能在len坐出贡献则一定会在len-1做出贡献。
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
int l[N];
int r[N];
#define x first
#define y second
typedef pair<int, int> pii;
int ans[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

    }
    stack<pii>st;
    for (int i = 1;i <= n;i++)
    {
        while (!st.empty() && st.top().first >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            l[i] = 1;
        }
        else
        {
            l[i] = st.top().second + 1;
        }
        st.push({ a[i],i });
    }
    while (st.size())st.pop();
    for (int i = n;i >= 1;i--)
    {
        while (!st.empty() && st.top().first >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            r[i] = n;
        }
        else
        {
            r[i] = st.top().second - 1;
        }
        st.push({ a[i],i });
    }
    for (int i = 1;i <= n;i++)
    {
        ans[r[i] - l[i] + 1] = max(ans[r[i] - l[i] + 1], a[i]);
    }
    for (int i = n - 1;i >= 1;i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
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