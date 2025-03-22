/*
!标签：二分答案
!题目：
给定两个数列：
数列A，长度为n，包含n个整数。
数列B，长度为m，包含m个整数。
构造一个n×m的矩阵C，其中每个元素C[i, j]定义为A[i] × B[j]。
找出矩阵C中的第K大的数。
!题解：
使用二分值域
然后检测当前答案是否成立
重点：该题有负数，
但是也有单调性，则需要两个指针，分别指向头和尾。
根据当前二分的答案是正数或者是负数进行分类考虑。
*/
//只有正数的情况怎么考虑⬇️
// cnt of A[i] * B[j] >= x
i64 find(i64 x)
{
    i64 ret = 0;
    int idx = 0;
    for (int i = n - 1; i >= 0 && idx < n; --i)
    {
        i64 target = (x / A[i]) + (x % A[i] > 0);
        while (idx < n && B[idx] < target)
            ++idx;
        ret += (n - idx);
    }
    return ret;
}
int main()
{
    n = rd(), k = rd();
    for (int i = 0; i < n; ++i)
        A[i] = rd(), B[i] = rd();
    sort(A, A + n), sort(B, B + n);
    i64 lo = A[0] * B[0], hi = A[n - 1] * B[n - 1] + 1;
    while (lo < hi)
    {
        i64 mi = (lo + hi) >> 1;
        if (find(mi) >= k)
            lo = mi + 1;
        else
            hi = mi;
    }
    wr(lo - 1);
}
