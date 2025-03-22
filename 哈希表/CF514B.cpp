/*
!标签：1300 + 哈希表
!题目：
有 n 个恐怖分子站在一个平面上，每个恐怖分子都有一个位置坐标位置 (x, y)。现在有一个激光武器要用来消灭这些恐怖分子，这个武器所在的位置是 (x0, y0)，激光武器每发射一次，就可以消灭一条直线上的所有恐怖分子。

现在，你的任务是计算最少要动用多少次激光武器，才可以消灭所有的恐怖分子。
!题解：
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
    int n, x0, y0;cin >> n >> x0 >> y0;
    unordered_set<string>st;
    for (int i = 1; i <= n; i++)
    {
        int x, y;cin >> x >> y;
        x -= x0;
        y -= y0;
        int d = __gcd(x, y);
        x /= d;
        y /= d;
        string u = to_string(x) + "_" + to_string(y);
        st.insert(u);
        look(u);
    }
    cout << st.size() << endl;
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