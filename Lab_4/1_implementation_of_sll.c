#include <stdio.h>
#include <stdlib.h>

struct  SLL
{
    int data;
    struct SLL *next;
};
struct SLL * first , *last = NULL;
struct SLL* create_node(int element){
    struct SLL *NewNode;
    NewNode = (struct SLL*) malloc (sizeof(struct SLL));
    if (NewNode != NULL)
    {
        NewNode ->data= element;
        NewNode -> next = NULL;
    }
    return NewNode;
}
void insert_at_beginning ( int element)
{
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation failed!!\n");
    }
    else 
    {
        if (first == NULL)
        {
            first = last = NewNode;
        }
        else {
            NewNode -> next = first;
            first = NewNode;
        }
        printf("%d was inserted.\n",first -> data);
    }
}

void insert_at_end(int element){
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation failed!!\n");
    }
    else 
    {
        if (first == NULL)
        {
            first = last = NewNode;
        }
        else {
            last -> next = NewNode;
            last = NewNode;
        }
        printf("%d was inserted.\n",last -> data);
    }
}

void insert_at_specific_position(int element, int position)
{
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL)
    {
        printf("Memory allocation failed!!\n");
    }
    else 
    {
        if (first == NULL)
        {
            first = last = NewNode;
        }
        else {
            last -> next = NewNode;
            last = NewNode;
        }
        printf("%d was inserted.\n",last -> data);
    }
}

void delete_at_beginning()
{
    
    if(first == NULL){
        printf("List is empty!!");
    }
    else if (first -> next == NULL){
        struct SLL *temp = first;
        first = last = NULL;
        free(temp);
    }
    else {
        struct SLL *temp = first;
        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        last = temp;
    }
    
}

void display()
{
    struct SLL *temp = first;
    if ( first == NULL)
    {
        printf("Empty list \n");
    }
    else{
        do {
            printf("%d -> ",temp -> data);
            temp = temp -> next;
        }while( temp != NULL);
        printf("NULL\n");
        
    }
}

int main ()
{
    insert_at_beginning(100);
    display();
    insert_at_beginning(200);
    display();
    insert_at_end(300);
    display();
    return 0 ;
}