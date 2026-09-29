#include <stdio.h>

int main()
{
    int n, i, key;
    int low, high, mid;
    int comparisons = 0;
    int found = 0;

    printf("Enter number of employee IDs: ");
    scanf("%d", &n);

    int id[n];

    printf("Enter %d employee IDs in ascending order:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &id[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if (id[mid] == key)
        {
            found = 1;
            break;
        }
        else if (key < id[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found == 1)
    {
        printf("Employee ID %d found at position %d\n", key, mid + 1);
    }
    else
    {
        printf("Employee ID %d is absent\n", key);
    }

    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}