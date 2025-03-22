/*
!标签：观察最左端和最右端
!题目：
给定一个1到 5的排列a。在一次操作中，你可以选择一个满足 a[i] < a[i+1] 的下标i(1 ≤i<n)，删除a[i]或a[i+1]
你需要求出是否可能通过若干次操作使得a只剩下一个元素。
n<=1e5;
!题解：
考虑到最左侧的值不减，最右侧的值不增，最后一次变换则是:a[i]<a[i+1];
则左侧需要保留最小值，右侧保留最大值。
考虑样例:
2 4 6 1 3 5
则最后一次操作的序列是: 2 5;
所以，直接判断a[1]<a[n];
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
    int n;cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << (a[1] < a[n] ? "YES" : "NO") << endl;
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