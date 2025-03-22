/*
!标签：1900+区间DP+排序
!题目：
给定一个长度为 2 × n 的数组， 1 到 n 每个元素恰好出现两次
每次操作可以删除一个长度不小于 2的连续子数组，需要满足该子数组.
首尾相同，获得该连续子数组“首尾元素值”乘以“元素数量”的分数
问最终可以得到的最大分数
1≤ai ≤ n≤ 3000
!题解：
 1 到 n 每个元素恰好出现两次->[l1,r1];代表数字1所在区间得分
dp数组是临时数组:用于解决区间覆盖问题
如果当前大区间中有小区间,则dp[k] = dp[k - 1] + num;这一步可以将算进大区间合并时.
(很关键)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e3 + 10;

int a[maxn * 2]; // 原始序列

struct s
{
    int p1, p2; // 该数字第1次(p1)、第2次(p2)出现的索引
} sz[maxn];

ll dp[maxn * 2];//当前[li,k]最大贡献
ll f[maxn];//区间[li,ri]的最大贡献
int b[maxn]; // 存储处理顺序

inline bool cmp(int x, int y)
{
    return sz[x].p2 - sz[x].p1 < sz[y].p2 - sz[y].p1;
}

signed main()
{
    int n;
    cin >> n;

    // 初始化1~n的两个索引
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        if (sz[a[i]].p1 == 0)
            sz[a[i]].p1 = i;
        else
            sz[a[i]].p2 = i;
    }
    sz[0].p1 = 0, sz[0].p2 = 2 * n + 1;
    // 根据区间长度从小到大排序
    for (int i = 0; i <= n; i++)
    {
        b[i] = i;
    }
    sort(b, b + n + 1, cmp);
    //从小到大处理每个区间.
    for (int i = 0; i <= n; i++)
    {
        //b[i]:当前数字
        //a[i]:当前位置
        int num = b[i];
        memset(dp, 0, sizeof(dp));  // 注意每一轮刷新
        int Li = sz[num].p1, Ri = sz[num].p2;
        for (int k = Li; k <= Ri; k++)
        {
            dp[k] = dp[k - 1] + num;
            if (k == sz[a[k]].p2 && sz[a[k]].p1 > Li)
            {
                dp[k] = max(dp[k], dp[sz[a[k]].p1 - 1] + f[a[k]]);
            }
        }
        f[num] = dp[Ri];
    }
    cout << f[0];
    return 0;
}