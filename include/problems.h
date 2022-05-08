#ifndef problems_h
#define problems_h

#include <stdlib.h>

int grid_paths(int n, int m, int* count)
{
    (*count)++;
    if(n == 1 || m == 1)
        return 1;
    else
        return grid_paths(n, m-1, count) + grid_paths(n-1,m, count);
}

int count_partitions(int n, int m)
{
    if(n < 0 || m == 0)
        return 0;
    else if(n == 0 || m == 1)
        return 1;
    else
        return count_partitions(n - m, m) + count_partitions(n, m - 1);
}

int ack(int m, int n)
{
    int ans;
    if(m == 0) ans = n+1;
    else if (n == 0) ans = ack(m-1,1);
    else ans = ack(m-1, ack(m, n-1));
    return ans;
}

#endif /* problems_h */
