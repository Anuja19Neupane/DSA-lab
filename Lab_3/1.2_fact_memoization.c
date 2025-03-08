#include <stdio.h>
long long int table[1000];
long long int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        if (table[n] == -1)
            table[n] = n * factorial(n - 1);
        return table[n];
    }
}
int main()
{
    long long int n, i;
    printf("Enter the value: ");
    scanf("%lldd", &n);
    for (i = 0; i < 1000; i++)
        table[i] = -1;
    printf("The factorial is: %lld \n", factorial(n));
    return 0;
}