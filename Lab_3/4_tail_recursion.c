#include <stdio.h>
long int factorial(int number, long int acc)
{
    if (number == 1)
        return acc;
    else 
        return factorial(number-1, acc*number);
}
int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d",&number);
    printf("Factorial is %ld\n",factorial(number,1));
    return 0;
}