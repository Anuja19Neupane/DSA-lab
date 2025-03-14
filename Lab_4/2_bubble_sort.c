#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort(int A[], int n)
{
    int i,j, temp;
    for (i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if (A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void display(int A[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d  \t" , A[i]);
    }
    printf("\n");
}

int main()
{
    int i,n, A[100001];
    float diff;
    clock_t start , end;
    srand(time(NULL));
    printf("How much n?");
    scanf("%d", &n);
    for (i = 0; i<n; i++)
        A[i] = rand();
    display(A,n);
    start = clock();
    bubble_sort(A,n);
    end = clock();
    display(A,n);
    diff = end-start;
    printf("Time = %f seconds\n", (float)(diff/CLOCKS_PER_SEC));
    return 0;
}