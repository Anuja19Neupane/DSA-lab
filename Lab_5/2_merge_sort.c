#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int l, int m, int r)
{
    int i = l, j = m, k = l, B[100000];

    while (i < m && j <= r)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i < m)
        B[k++] = A[i++];
    while (j <= r)
        B[k++] = A[j++];

    for (k = l; k <= r; k++)
        A[k] = B[k];
}

void merge_sort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(A, l, m);
        merge_sort(A, m + 1, r);
        merge(A, l, m + 1, r);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
}

int main()
{
    int i, n, A[100001];
    clock_t start, end, diff;
    srand(time(NULL));

    printf("How many numbers? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        A[i] = rand();

    display(A, n);
    start = clock();
    merge_sort(A, 0, n - 1);
    end = clock();
    display(A, n);
    diff = end - start;
    printf("Time = %f seconds\n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}
