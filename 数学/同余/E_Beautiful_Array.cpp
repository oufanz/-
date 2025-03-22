/*
!标签：余数分类+重要技巧
!题目：https://codeforces.com/contest/1986/problem/E
给定一个数组，可以对这个数组重排列，每次可以进行一次操作
 将a[i]+=k;
求让数组对称的最小操作次数
!题解：
由于对称则: x+n*k=y+m*k;即只有两个数的取模于k的值相等才有可能最后相等
先将所有的数分组。如果某一组别恰好为偶数个则直接从小到大考虑
为奇数个，则需要考虑每次将哪一个元素去除掉（当作对称中心）。
此时先不考虑vi[0]计算出一个res;然后依次不考虑vi[i];
即ans-=(vi[i+1]-vi[i]/k);//将原本的删掉
ans+=(vi[i]-vi[i-1]/k);//加上现在考虑的
因为vi[i]只会与vi[i+1]结合才对答案有贡献，所以这样做可行。
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
void solve()
{
    map<int, vector<int>>mp;
    int n;cin >> n;
    int k;cin >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i] % k].push_back(a[i]);
    }
    int cnt = n & 1;
    int ans = 0;
    for (auto& [key, vi] : mp)
    {
        sort(vi.begin(), vi.end());
        if (vi.size() % 2 != 0)
        {
            if (cnt)
            {
                cnt--;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        if (vi.size() % 2 == 1)
        {
            int tmp = 0;
            int res = 0;
            for (int i = 1;i < vi.size();i += 2)
                tmp += ((vi[i + 1] - vi[i]) / k);
            res = tmp;
            for (int i = 1;i < vi.size();i += 2)
            {
                //即不要第i个:
                tmp -= ((vi[i + 1] - vi[i]) / k);
                tmp += ((vi[i] - vi[i - 1]) / k);
                res = min(res, tmp);
            }
            ans += res;
        }
        else
        {
            for (int i = 0;i < vi.size();i += 2)
            {
                ans += (vi[i + 1] - vi[i]) / k;
            }
        }
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