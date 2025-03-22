/*
!标签：1300+贡献法
!题目：
https://atcoder.jp/contests/abc045/tasks/arc061_b
题目描述
我们有一个 H 行 W 列的网格。起初，所有单元格都是白色的。
Snuke 把这个网格中的 N 个单元格涂成了黑色。第 i 个 (1≤i≤N) 被涂黑的单元格位于第 a[i] 行和第 b[i] 列。
计算以下内容：
对于每个整数 j (0≤j≤9)，在 Snuke 涂黑了 N 个单元格后，有多少个大小为 3×3 的子矩形恰好包含 j 个黑色单元格？
约束条件
3≤H≤10^9
3≤W≤10^9
0≤N≤min(10^5, H×W)
1≤a[i]≤H (1≤i≤N)
1≤b[i]≤W (1≤i≤N)
(a[i], b[i]) ≠ (a[j], b[j]) (i≠j)
!题解：
考虑每次加入的黑方格所影响的矩形有多少个？9个
map记录以{x,y}为中心的矩形所含方格数。依次算贡献即可。
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
int  ans[10];
typedef pair<int, int> pii;//用pair来维护二元组 
map<pii, int> mp;
void solve()
{
    int h, w;
    int n;
    cin >> h >> w >> n;
    ans[0] = (h - 2) * (w - 2);//初始化，一开始一个黑格子都没有 
    for (int i = 1;i <= n;i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = -1;j <= 1;j++)
        {
            for (int k = -1;k <= 1;k++)//遍历计算影响 
            {
                int x = a + j, y = b + k;//九宫格的中心 
                if (x > 1 && x < h && y>1 && y < w)//判断边界 
                {
                    int now;//now表示现在这个九宫格的黑格子的数量 
                    now = ++mp[{x, y}];
                    ans[now]++, ans[now - 1]--;
                }
            }
        }
    }
    for (int i = 0;i < 10;i++) cout << ans[i] << endl;
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