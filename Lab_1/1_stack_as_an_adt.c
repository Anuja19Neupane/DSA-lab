#include<stdio.h>
#include<string.h>
#define Max 5

struct employee
{
    int TOS;
    char name[Max][20];
    int id[Max];
};

int isfull(struct employee *e)
{
    return e->TOS == Max-1? 1:0;
}

int isempty(struct employee *e)
{
    return e->TOS == -1? 1:0;
}

void push(struct employee *e, int id, char name[20])
{
    e->TOS += 1;
    strcpy(e->name[e->TOS], name);
    e->id[e->TOS] = id;
    printf("Employee pushed to stack..\n");
}

void pop(struct employee *e)
{
    if(e->TOS == -1) {
        printf("Stack underflow!!!!!\n");
    }
    else{
        printf("Name = %s, ID = %d, \n", e->name[e->TOS], e->id[e->TOS]);
        e->TOS -= 1;
    }
}

int main()
{
    struct employee emp = {-1};
    int choice;
    char name[20];
    int id;
    while(1){
        printf("\n1. PUSH: \n2. POP: \n3. EXIT:");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice){
            case 1: if(isfull(&emp)){
                printf("Stack Overflow..\n");
            }
            else{
                printf("Enter the employee name:");
                scanf("%s", name);
                printf("Enter the employee ID: ");
                scanf("%d", &id);
                push(&emp,id,name);
            }
            break;

            case 2:if(isempty(&emp)){
                printf("Stack Underflow..\n");
            }
            else{
                pop(&emp);
            }
            break;
            
            case 3: printf("Exiting...\n");
            return 0;

            default : printf("Invalid choice! \nPlease try the valid number (1,2,3)\n");
        }
    }
    return 0;
}