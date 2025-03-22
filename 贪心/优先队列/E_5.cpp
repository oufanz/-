/*
!标签：排序+优先队列贪心+1300
!题目：
https://atcoder.jp/contests/abc325/tasks/abc325_d?lang=en
问题陈述

在一条传送带上有 N 个标有 1 至 N 的产品在流动。传送带上安装了一台 Keyence 打印机，产品 i 在 T[i] 微秒后进入打印机的打印范围，并在 D[i] 微秒后离开打印机。

KEYENCE 打印机可以立即打印打印机范围内的一个产品（尤其是在产品进入或离开打印机范围的瞬间）。但打印一次后，需要充电 1 微秒才能再次打印。如果产品和打印机打印时间选择最优，打印机最多可以打印多少产品？

!题解：
首先由一个很显然的贪心当在同一时刻内在打印机里面的物品，显然现将最早退出打印机的打印最优。
即需要找到当前时刻能打印的全部物品中y最小的值。
*/
#include <bits/stdc++.h>
#define re register
#define int long long

using namespace std;

const int N = 2e5 + 10, inf = (int)(2e18) + 10;
int n, ans;
priority_queue<int, vector<int>, greater<int>> q;

struct point
{
    int l;
    int r;

    friend bool operator <(const point& a, const point& b)
    {
        return a.l < b.l;
    }
}arr[N];

inline int read()
{
    int r = 0, w = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        r = (r << 3) + (r << 1) + (c ^ 48);
        c = getchar();
    }
    return r * w;
}

signed main()
{
    n = read();
    for (re int i = 1;i <= n;i++)
    {
        int x, l;
        x = read();
        l = read();
        arr[i] = { x,x + l };
    }
    arr[n + 1] = { inf,inf };
    sort(arr + 1, arr + n + 1);
    for (re int i = 1;i <= n;i++)
    {
        int j = i, now = arr[i].l;
        while (j <= n && arr[j].l == now) q.push(arr[j++].r);
        while (!q.empty() && now < arr[j].l)
        {
            int t = q.top();
            q.pop();
            if (t >= now)
            {
                now++;
                ans++;
            }
        }
        i = j - 1;
    }
    printf("%lld", ans);
    return 0;
}