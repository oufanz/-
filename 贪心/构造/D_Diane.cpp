/*
关键字:构造+结论 ,手玩
构造一个长度为𝑛的由小写字母构成的字符串，使得字符串内每个字串出现奇数次。
方法:考虑到用长度为n和n-1的相同字符串拼接而成,即可满足条件
例如n=6,aaabaa即可
n=7 ,aaabcaa即可
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
const int N = 1e6 + 10, INF = 1e17;
void solve()
{
    int n;
    cin >> n;
    string s;
    if (n <= 26)
    {
        for (int i = 0;i < n;i++) s += 'a' + i;
        cout << s << endl;
        return;
    }
    if (n % 2 == 0)
    {
        for (int i = 1;i < n / 2;i++) s += 'a';
        s += 'b';
        for (int i = n / 2 + 1;i <= n;i++) s += 'a';
    }
    if (n % 2 != 0)
    {
        for (int i = 1;i < n / 2;i++) s += 'a';
        s += 'b', s += 'c';
        for (int i = n / 2 + 1;i <= n - 1;i++) s += 'a';
    }
    cout << s << endl;
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
//ed