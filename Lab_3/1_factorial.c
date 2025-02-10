#include <stdio.h>
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int main()
{
    int number; 
    printf("Enter any number: \n");
    scanf("%d",&number);
    factorial(number);
    printf("Factorial of %d is: %d\n", number,factorial(number));
}