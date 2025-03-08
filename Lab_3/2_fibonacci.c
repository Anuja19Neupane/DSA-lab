#include <stdio.h>
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    int number;
    printf("Enter the term: \n");
    scanf("%d", &number);
    fibonacci(number);
    printf("Fibonacci of %dth is: %d\n", number, fibonacci(number));
}