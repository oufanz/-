/*
!标签：前缀和维护区间信息，查询（预处理部分+即时边界处理）,模拟
!题目：https://codeforces.com/contest/1978/problem/E
!题解：
1.观察操作：优先执行1操作再执行2操作肯定更优
2.对于查询的字符串[l,r]，其中[l+1,r-1]可以离线处理出来
3.至于边界情况al,al+1,ar-1,ar能否变成1，可以在线考虑。
4.难点：如果判断当前a[i]是否可以变成1
情况1：b[i-1]=1,b[i+1]=1;直接变成1
情况2:b[i-1]=0,b[i+1]=0;但是a[i-2]=0，a[i+2]=0即可。
否则别无可能。
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
int s[N];
string a, b;
int n;
typedef pair<int, int> pii;
pii pre[N];
pii check(int i)
{
    if (a[i] == '1') return make_pair(i, i);


    int l = -1, r = -1;

    if (i - 1 >= 1 && b[i - 1] == '1') l = i - 1;
    else if (i - 2 >= 1 && b[i - 1] == '0' && a[i - 2] == '0') l = i - 2;


    if (i + 1 <= n && b[i + 1] == '1') r = i + 1;
    else if (i + 2 <= n && b[i + 1] == '0' && a[i + 2] == '0') r = i + 2;

    if (l == -1) r = -1;
    if (r == -1) l = -1;
    return make_pair(l, r);
}
void solve()
{
    cin >> n;
    cin >> a >> b;
    a = '*' + a;
    b = '*' + b;
    for (int i = 1;i <= n;i++)
    {
        s[i] = s[i - 1] + (check(i).first != -1);
    }
    int q;cin >> q;
    while (q--)
    {
        int l, r;cin >> l >> r;
        int ans = 0;
        if (r - l <= 5)
        {
            for (int i = l; i <= r; i++)
            {
                auto [ll, rr] = check(i);
                if (ll >= l && rr <= r) ans++;
            }
        }
        else
        {
            ans = s[r] - s[l - 1];
            for (int j : {l, l + 1, r - 1, r})
            {
                auto [ll, rr] = check(j);
                if (ll != -1 && (ll < l || rr > r)) ans--;
            }
        }
        cout << ans << endl;
    }
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