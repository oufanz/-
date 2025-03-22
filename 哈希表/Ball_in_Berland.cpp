/*
!标签：哈希表+容斥原理
!题目：
在毕业典礼上，有 a 个男孩和 b 个女孩准备跳舞，不是所有的男孩和女孩都准备结伴跳舞。
现在你知道 k 个可能的舞伴，你需要选择其中的两对，以便使没有人重复地出现在舞伴里，求可能的数量。
1 ≤ a, b, k ≤ 2 * 10^5
!题解：
容斥原理:
ans{1,2}-ans{1,?}-ans{?,2}+ans{1,2};
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
int b[N];
int cnt1[N];
int cnt2[N];
#define x first
#define y second
typedef pair<int, int> pii;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cnt1[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cnt2[i] = 0;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    map<pii, int>mp;
    for (int i = 1; i <= k; i++)
    {
        ans += i - 1;
        ans -= cnt1[a[i]];
        ans -= cnt2[b[i]];
        ans += mp[{a[i], b[i]}];
        cnt1[a[i]]++;
        cnt2[b[i]]++;
        mp[{a[i], b[i]}]++;
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