#include <stdio.h>
#define MAX 10
struct Queue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};
void Enqueue(struct Queue *Q, int element)
{
    if (Q->REAR == MAX - 1)
    {
        printf("Queue is full!!");
    }
    else
    {
        Q->REAR += 1;
        Q->DATA[Q->REAR] = element;
    }
}
int Dqueue(struct Queue *Q)
{
    int element;
    if (Q->REAR < Q->FRONT)
    {
        printf("Queue is empty!!!\n");
        return -1;
    } 
    else
    {
        element = Q->DATA[Q->FRONT];
        Q->FRONT += 1;
    }
    return element;
}

int main()
{
    int choice;
    int input;
    struct Queue Q = {0, -1}; // front and rear
    while (1)
    {
        printf("Enter 1 for Enqueue and 2 for Dequeue: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the value in queue: ");
            scanf("%d", &input);
            Enqueue(&Q, input);
        }
        if (choice == 2)
        {
            int Output = Dqueue(&Q);
            if (Output != -1)
                printf("%d\n", Output);
        }
    }
    return 0;
}