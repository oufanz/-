/*
题目:https://codeforces.com/problemset/problem/919/D
标签:拓扑排序+DP
*/
#include<bits/stdc++.h>
using namespace std;
int n, m, b[300005], in[300005], f[300005][26];
int ans, cnt, x, y;
string s;
vector<int> g[300005];
queue<int> q;
void solve()
{
    cin >> n >> m;
    cin >> s;
    for (int i = 1;i <= n;i++) b[i] = s[i - 1] - 'a', f[i][b[i]]++;
    for (int i = 1;i <= m;i++)
    {
        cin >> x >> y;
        in[y]++;
        g[x].push_back(y);
    }
    for (int i = 1;i <= n;i++) if (!in[i]) q.push(i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto v : g[u])
        {
            for (int j = 0;j < 26;j++)
            {
                if (b[v] == j) f[v][j] = max(f[v][j], f[u][j] + 1);
                else f[v][j] = max(f[v][j], f[u][j]);
            }
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    if (cnt < n) cout << -1 << endl;
    else
    {
        for (int i = 1;i <= n;i++)
        {
            for (int j = 0;j < 26;j++) ans = max(ans, f[i][j]);
        }
        cout << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}