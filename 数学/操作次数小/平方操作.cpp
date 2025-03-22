/*
!标签：前缀和+数学
!题目：
ikrpprpp 找到一个由整数组成的数组 a。他喜欢公正，所以他想让 a 变得公平——也就是说，让它变为非递减的。为此，他可以对数组的一个索引 1 ≤ i ≤ n 执行一次公正行为，这将把 a[i] 替换为 a[i] 的平方。例如，如果 a = [2, 4, 3, 3, 5, 3] 并且 ikrpprpp 选择在 i = 4 进行公正行为，则 a 变为 [2, 4, 3, 9, 5, 3]。
使数组变为非递减所需的最小公正行为次数是多少？
!题解：
考虑记录每一个位置需操作多少次即可。
当前数比之前数大，则考虑当前需要少操作多少次。
当前数比之前数小，则需要多操作多少次。
a[i-1]^(2^p)
a[i]^(2^q)
已知p
可以直接推出最小的q;
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
vector<int>v;
int n;
void solve()
{
    cin >> n;
    v.resize(n);
    for (auto& i : v)
        cin >> i;

    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] > 1 && v[i] == 1)
        {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ops(n, 0);//每个位置所需操作次数.


    for (int i = 1; i < n; i++)
    {
        int him = v[i - 1];
        int me = v[i];
        int extra = 0;
        while (me < him)
            extra++, me *= me;
        //当前面的数平方小于当前的数。
        while (him != 1 && him * him <= me)
            extra -= 1, him *= him;

        ops[i] = max(0ll, ops[i - 1] + extra);
        cout << ops[i] << ' ';
    }
    cout << endl;

    int ans = 0;
    for (auto i : ops)
        ans += i;
    cout << ans << "\n";
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