/*
https://codefun2000.com/p/P1010
!现在塔子哥拿到了一个数组arr，每次操作可以将数组arr中的一个数+1，求用至多d次操作将这个数组变为一个 G阶数组后的最大值为多少，如果不能变成合法的G阶数组则输出-1
!G阶数组满足：一个数组中的每个长度为G的连续子数组的和都相等。
*/
#include <iostream>
#include <vector>
using namespace std;
int a[100005];
int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int>p[k];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i % k].push_back(a[i]);
    }
    int ans = -1000000000;
    for (int i = 0; i < k; i++)
    {
        int mxx = -1000000000;
        int sum = 0;
        for (int j = 0; j < p[i].size(); j++)
        {
            mxx = max(mxx, p[i][j]);
            sum += p[i][j];
        }
        x -= mxx * p[i].size() - sum;	//所需的最小操作次数：让这len(tmp)个数都变成max(tmp)
    }
    if (x >= 0)
    {	//如果剩余操作次数为负，说明不够，输出-1，否则求一下最大值
        for (int i = 0; i < k; i++)
        {
            int mxx = -1000000000;
            for (int j = 0; j < p[i].size(); j++)
            {
                mxx = max(mxx, p[i][j]);
            }
            ans = max(ans, mxx + x / (int)p[i].size());//此时的最大值 max(tmp) + x//len(tmp) ，就是把x次操作均分到每个数上让整体变大
        }
        cout << ans << endl;	//最后输出最大值
    }
    else
        cout << -1 << endl;		//操作次数不够
    return 0;
}
