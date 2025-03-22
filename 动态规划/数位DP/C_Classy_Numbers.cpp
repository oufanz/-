/*
!标签：数位DP，从L->R,没有前导0，如果前导0需要使用2.0版本
!题目：
一个数字是“好数”，当且仅当它的十进制表示下有不超过3 个1∼9 之间的数字。
!题解：
板子题，直接套模板
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
string s;//数字范围.
int len;
int dp[20][4][2][2];//数字位数,需要记录的状态,
int dfs(int pos, int mask, bool is_limit, bool is_num)
{
    // int tot = __builtin_popcount(mask) - (mask & 1);
    if (mask > 3) return 0;
    //结束条件：填完每一位，如果当前是数字则满足条件
    if (pos == len)
        return is_num;
    //记忆化
    int& res = dp[pos][mask][is_limit][is_num];
    if (res != -1) return res;
    res = 0;//初始化res值
    //依旧不填数字
    if (!is_num)
        res += dfs(pos + 1, mask, false, false);
    //当前可以填的数字上界
    int up = is_limit ? s[pos] - '0' : 9;
    //枚举当前填什么数字
    for (int d = 1 - is_num;d <= up;d++)
    {
        res += dfs(pos + 1, mask + (d != 0), is_limit & d == up, true);
    }
    return res;
}
int cal(int num)
{
    s = to_string(num);
    len = s.size();
    memset(dp, -1, sizeof dp);
    return dfs(0, 0, true, 0);
}
void solve()
{
    int l, r;cin >> l >> r;
    cout << cal(r) - cal(l - 1) << endl;
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