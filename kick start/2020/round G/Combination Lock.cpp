#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
using namespace std; // since cin and cout are both in namespace std, this saves some text

long long dp[100100];
long long sum[100100];
int main()
{
    int t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int w, n;
        scanf("%d %d", &w, &n);
        for (int i = 0; i < w; i++)
        {
            scanf("%lld", dp + i);
        }
        sort(dp, dp + w);
        sum[0] = dp[0];
        for (int i = 1; i < w; i++)
        {
            sum[i] = dp[i] + sum[i - 1];
        }
        long long ret = LONG_MAX;
        int x = 0; 
        int y = 0;
        for (int i = 0; i < w; i++)
        {
            int l = x;
            int r = i;
            int j = i;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                int a = dp[i] - dp[m]; // decrasing
                int b = n - a;         // increasing
                if (a == b)
                {
                    j = m;
                    break;
                }
                else if (a > b)
                {
                    l = m + 1;
                }
                else
                {
                    j = m;
                    r = m - 1;
                }
            }
            x = j; 
            long long tmp = (i - j + 1) * dp[i] - (j > 0 ? (sum[i] - sum[j - 1]) : sum[i]);
            if (j > 0)
            {
                tmp += sum[j - 1] + j * (n - dp[i]);
            }
            l = y;
            r = w - 1;
            j = i;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                int a = dp[m] - dp[i]; // increasing
                int b = n - a;
                if (a == b)
                {
                    j = m;
                    break;
                }
                else if (a > b)
                {
                    r = m - 1;
                }
                else
                {
                    j = m;
                    l = l + 1;
                }
            }
            y = j; 
            long long tmp1 = (i > 0 ? (sum[j] - sum[i - 1]) : sum[j]) - (j - i + 1) * dp[i];
            tmp1 += (long long)(w - j - 1) * (dp[i] + n) - (sum[w - 1] - sum[j]);
            ret = min(ret, tmp + tmp1);
        }
        cout << "Case #" << i << ": " << ret;
        if (i != t)
        {
            cout << endl;
        }
    }
}