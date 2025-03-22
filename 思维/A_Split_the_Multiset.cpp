/*
!标签：反向思考
!题目：
集合中已经有一个数 n,每次可以选择集合中的一个数分解成k个数,目的是将他分解成n个1
求最小操作次数.
例如n=6,k=3;
第一次分解:{6}->{1,2,3};
第二次分解:{1,2,3}->{1,1,1,3};
第三次分解:{1,1,1,1,1,1};
最少三次.
!题解：
考虑每次操作可以增加(k-1)个数.
则从1个数->n个数.
ans=ceil((n-1)/(k-1));
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
    int n, k;
    cin >> n >> k;
    cout << ceil((n - 1) * 1.0 / (k - 1)) << endl;
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