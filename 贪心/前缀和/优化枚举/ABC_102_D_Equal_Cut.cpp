/*
!标签：双指针+前缀和优化
!题目：
Snuke有一个长度为N的整数序列A。
他将在A中进行三次切割，将其分成四个（非空）连续子序列B, C, D和E。切割的位置可以自由选择。
设P, Q, R, S分别是B, C, D, E中元素的和。Snuke在P, Q, R, S的最大值和最小值之间的绝对差较小时会更高兴。找出P, Q, R, S的最大值和最小值之间的最小可能绝对差。
约束条件
4 ≤ N ≤ 2 × 10^5
1 ≤ A[i] ≤ 10^9
输入中的所有值都是整数。
!题解：
考虑划分为：[1,i][i+1,j][j+1,k][k+1,n];
枚举j
设定指针i指向1，随着j右移，i一定单调递增;
当i=1,j=2时，k指向一个平衡点，k一定单调递增.
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
int s[N];
int S(int i, int j)
{
    return s[j] - s[i - 1];
}
void solve()
{
    int n;cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int ans = INF;
    for (int i = 1, j = 2, k = 3; j <= n; j++)
    {
        //[1,i][i+1,j][j+1,k][k+1,n];
        //注意一定用while
        while (abs(S(1, i) - S(i + 1, j)) > abs(S(1, i + 1) - S(i + 2, j)) && i + 1 <= j)
        {
            i++;
        }
        while (abs(S(j + 1, k) - S(k + 1, n)) > abs(S(j + 1, k + 1) - S(k + 2, n)) && k + 2 <= n)
        {
            k++;
        }
        vector<int>vi;
        vi.push_back(S(1, i));
        vi.push_back(S(i + 1, j));
        vi.push_back(S(j + 1, k));
        vi.push_back(S(k + 1, n));
        sort(vi.begin(), vi.end());
        ans = min(ans, vi[3] - vi[0]);
    }
    cout << ans << endl;
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