/*
题目:
你有一个序列 a，你可以进行 2 种操作：
选择前 k 个数，将它们全部减 1
选择后 k 个数，将它们全部减 1
k 由你自己定，并且每次操作可以不同。
问是否可以通过若干次操作将整个序列变为全是 0 的序列
标签:差分
对于差分数组a
操作1:等价于:a[1]--, a[i]++;
操作2 等价于:a[i]--,a[n+1]++;
显然看差分数组中>0的数即可;
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 10, INF = 1e17;
int a[N];
void solve()
{
    int n;cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = n;i >= 1;i--)
        a[i] -= a[i - 1];

    int sum = 0;
    for (int i = 2;i <= n;i++)
        if (a[i] < 0) sum -= a[i];
    if (a[1] >= sum)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}