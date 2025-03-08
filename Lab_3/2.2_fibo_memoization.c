#include <stdio.h>

long long int table[500];
long long int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        if (table[n] == -1)
        {
            table[n] = fibonacci(n - 1) + fibonacci(n - 2);
        }
        return table[n];
    }
}
int main()
{
    long long int number, i;
    printf("Enter the term: \n");
    scanf("%lld", &number);
    for (i = 0; i < 500; i++)
    {
        table[i] = -1;
    }
    printf("Fibonacci valu of %lldth is: %lld\n", number, fibonacci(number));
    return 0;
}