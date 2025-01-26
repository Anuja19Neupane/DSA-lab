/*wap in c to implement stack is an ADT .
 the stack should be able to store user define structure
*/
#include <stdio.h>
#define true 1
#define false 0
#define MAX 5

struct employee
{
    char name[20];
    int id;
};

struct stack
{
    int TOS; // Top of Stack
    struct employee emp[MAX];
};

// stack full xa ki xaina
int isFull(struct stack *s)
{
    if (s->TOS == MAX - 1) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

// stack empty xa ki xaina
int isEmpty(struct stack *s)
{
    if (s->TOS == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isFull false vaye, add employee to the stack
void push(struct stack *s, struct employee e)
{
    if (isFull(s))
    {
        printf("Stack Overflow! \n");
    }
    else
    {
        s->TOS += 1; // push garda jaile pani suruma TOS lai increase garney
        s->emp[s->TOS] = e;
        
    }
}

// isEmpty false vaye, stack bata 1st element nikal
void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow! \n");
    }
    else
    {
        struct employee e = s->emp[s->TOS]; // pop garda jaile pani suruma pop garney ani matra TOS lai decrease garney
        
        s->TOS -= 1;
    }
}

int main()
{
    struct stack s;
    s.TOS = -1; // stack lai empty parney

    int choice;
    struct employee e;

    printf("Welcome boss!\n");

    while (1)
    { // infinite loop ho , break use gareypaxi matra tutxa

        printf("Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {

            printf("Employee Name: ");
            scanf("%s", e.name);
            printf("Employee ID: ");
            scanf("%d", &e.id);
            push(&s, e);
        }
        else if (choice == 2)
        {

            pop(&s);
        }
        else if (choice == 3)
        {

            printf("Nothing to do!\n");
            break;
        }
        else
        {

            printf("Enter correct number!!\n");
        }
    }

    return 0;
}
