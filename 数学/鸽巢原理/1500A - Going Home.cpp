/*
考虑到总和不超过5e6;所以最多需要枚举5e6次。
*/
#include <bits/stdc++.h>
#define bug cout << "***************" << endl
#define look(x) cout << #x << " -> " << x << endl
#define int long long
#define endl '\n'
using namespace std;

const int N = 2.5e6 + 10, INF = 1e17;
int a[N];
pair<int, int> res[N * 2]; 

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int sum = a[i] + a[j];
            if (res[sum].first == 0 || res[sum].second == 0)
            {
                res[sum].first = i;
                res[sum].second = j;
            }
            else if (res[sum].first != i && res[sum].second != j && res[sum].first != j && res[sum].second != i)
            {
                cout << "YES" << endl;
                cout << res[sum].first << " " << res[sum].second << " " << i << " " << j << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
