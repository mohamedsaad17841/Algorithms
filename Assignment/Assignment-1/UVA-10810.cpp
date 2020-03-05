// GROUP:   3
// ID:      20170212
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    Mohamed Ahmed Saad Abouzaid

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

long long sorted[1000000];

long long CountInvMerge(long long *a, long long left, long long right)
{
    long long mid = (left + right) / 2;
    long long i = left;
    long long j = mid + 1;
    long long k = left;
    long long invCount = 0;

    while ((i <= mid) && (j <= right))
    {
        if (a[i] <= a[j]) {
            sorted[k++] = a[i++];
        }
        else
        {
            sorted[k++] = a[j++];
            invCount = invCount + mid - i + 1;
        }
    }

    while (i <= mid)
        sorted[k++] = a[i++];
    while (j <= right)
        sorted[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = sorted[i];

    return invCount;
}

long long CountInv(long long *a, long long left, long long right)
{
    long long mid, invCount = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        invCount = CountInv(a, left, mid);
        invCount += CountInv(a, mid + 1, right);
        invCount += CountInvMerge(a, left, right);
    }
    return invCount;
}

const int N = 1e6 + 5;
long long arr[N];
long long n;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    while(true)
    {
        cin >> n;
        if(n == 0) return 0;
        for(long long i = 0 ; i<n ; i++) cin >> arr[i];
        cout << CountInv(arr, 0 , n-1) << endl;
    }
}
