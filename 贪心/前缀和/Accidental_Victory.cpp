/*
!标签：前缀和+贪心+1400
!题目：
https://codeforces.com/problemset/problem/1490/E
有 n 支队伍参加比赛，每个队伍初始时有一些代币。
比赛每一轮随机挑两个代币数不为0的队伍，然后代币多的队伍获胜，代币少的队伍把代币全部给代币多的（代币数量相同则随机），直到最后只有一个队伍有代币， 这个队伍获胜。
求哪些队伍是有可能获胜的。
t ≤ 10^4
∑n ≤ 2 * 10^5
1 ≤ a[i] ≤ 10^9
!题解：
如代码
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
#define x first
#define y second
typedef pair<int, int> pii;
void solve()
{
    int n;cin >> n;
    int mx = 0;
    vector<pii>vi;
    vector<int>ans;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vi.push_back({ a[i],i });
        // mx = max(mx, a[i]);
    }
    sort(vi.begin(), vi.end());
    int sum = vi[0].first;
    ans.push_back(vi[0].second);
    for (int i = 1; i < n; i++)
    {
        if (sum < vi[i].first)
        {
            ans.clear();
        }
        ans.push_back(vi[i].second);
        sum += vi[i].first;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans) cout << it << ' ';
    cout << endl;
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