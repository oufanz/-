/*
询问一个区间有多少个数的：（数本身的值等于其在这个区间中出现的次数）
方法：考虑上限固定了,数的总数不超过500个(1+2+3+……+500)>1e5;
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#ifdef _DEBUG
#include "D:\OneDrive\VScode_project\cppDebug\debug.h"
#else
#define look(...) 42
#define bug 66
#endif
const int N = 1e5 + 10, INF = 1e17;
int a[N];
//st
void solve()
{
    int n;cin >> n;
    int m;cin >> m;
    map<int, int>mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int>vi;
    for (int i = 1; i <= n; i++)
    {
        if (mp[a[i]] >= a[i])
        {
            vi.push_back(a[i]);
            mp[a[i]] = 0;
        }
    }
    vector <vector<int>>cnt(n + 1, vector<int>((int)vi.size() + 1, 0));
    for (int i = 1;i <= n;i++)
    {
        for (int j = 0;j < vi.size();j++)
        {
            cnt[i][j] = cnt[i - 1][j] + (vi[j] == a[i]);
        }
    }
    while (m--)
    {
        int l, r;cin >> l >> r;
        int ans = 0;
        for (int i = 0;i < vi.size();i++)
        {
            if (cnt[r][i] - cnt[l - 1][i] == vi[i])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
//ed

//st
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
//ed