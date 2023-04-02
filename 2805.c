#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i;
    int* tree_list;
    long long left, mid, right, sum, max, cut_max;

    scanf("%d %d", &n, &m);
    tree_list = (int*)malloc(n * sizeof(int));

    for (i = 0, max = 0; i < n; i++)
    {
        scanf(" %d", &tree_list[i]);
        if (max < tree_list[i])
        {
            max = tree_list[i];
        }
    }

    left = 1, right = max, cut_max = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;

        for (i = 0, sum = 0; i < n; i++)
        {
            if (tree_list[i] - mid > 0)
            {
                sum = sum + (tree_list[i] - mid);
            }
        }
        if (sum < m)
        {
            right = mid - 1;
        }
        else
        {
            if (cut_max < mid)
            {
                cut_max = mid;
            }
            left = mid + 1;
        }
    }

    printf("%lld\n", cut_max);

    free(tree_list);
    return 0;
}