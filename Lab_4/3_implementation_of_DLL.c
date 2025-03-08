#include<stdio.h>
#include<stdlib.h>
struct DLL
{
    int data;
    struct DLL*prev;
    struct DLL*next;
};
struct DLL *first,*last=NULL;
struct DLL* create_node(int element)
{
struct DLL*NewNode;
NewNode=(struct DLL*)malloc(sizeof(struct DLL));
if(NewNode!=NULL)
{
    NewNode->data=element;
    NewNode->prev=NULL;
    NewNode->next=NULL;
}
return NewNode;
}

void insert_at_beginning(int element)
{
    struct DLL*NewNode=create_node(element);
    if(NewNode==NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        if(first== NULL)
        first=last=NewNode;
        else
        {
            NewNode->next=first;
            first->prev=NewNode;
            first=NewNode;
        }
        printf("%d was inserted at the beginning\n",first->data);
    }
}

void insert_at_end(int element)
{
    struct DLL*NewNode=create_node(element);
    if(NewNode==NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    else
    {
        if(first==NULL)
        first=last=NewNode;
        else
        {
            last->next=NewNode;
            NewNode->prev=last;
            last=NewNode;
        }
        printf("%d was inserted at the end\n",last->data);
    }

}

void insert_at_specific_position(int element,int pos)
{
    struct DLL*NewNode=create_node(element);
    {
        if(pos==1)
        {
            NewNode->next=first;
            first->prev=NewNode;
            first=NewNode;
        }
        else
        {
            struct DLL*temp;
            temp=first;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
             struct DLL*tempp;
             tempp=temp->next;
             temp->next=NewNode;
             NewNode->prev=temp;
             NewNode->next=tempp;
             tempp->prev=NewNode;
            }
            printf("%d was inserted at the  position %d \n",element,pos);

        }
}

void deletion_at_beginning()
{
    struct DLL*temp;
    temp=first;
        if(first== NULL)
        {
        printf("list is empty\n");
        return;
        }

        else if(first->next==NULL)
        {
           temp=first;
           first=last=NULL;
           free(temp);
        }
        else
        {
        temp=first;
        printf("%d was deleted at the beginning \n",temp->data);
        first=first->next;
        first->prev=NULL;
        free(temp);
        }
        
}

void deletion_at_end()
{
    struct DLL*temp;
    temp=first;
        if(first== NULL)
        {
        printf("list is empty\n");
        return;
        }

        else if(first->next==NULL)
        {
           temp=first;
           first=last=NULL;
           free(temp);
        }
        else
        {
        temp=first;
        printf("%d was deleted at the end \n",last->data);
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        last=temp->prev;
        last->next=NULL;;
        free(temp);
        }
        
}

void deletion_at_specific_position(int pos)
{
    struct DLL*temp;
    temp =first;
         if (first == NULL) 
         {
        printf("List is empty\n");
        return;
         }
         if(pos== 1)
         {
            first=first->next;
            free(temp);
         }
         else
         {
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            if(temp->next==last)
            {
                last=temp;
                temp=last->next;
                free(temp);
                last->next=NULL;
            }
            else
            {
                struct DLL*tempp;
                tempp=temp->next;
                printf("%d was deleted at the position %d\n",tempp->data, pos);
                temp->next=tempp->next;
                free(tempp);
            }
        }
}

void search(int key)
{
    struct DLL *temp;
    temp =first;
    int flag=0;
    if(first==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    do
    {
        if(temp->data==key)
        {
            flag=1;
            printf("Element found\n");
            break;
        }
        temp=temp->next;
    } while (temp!=NULL);
    if(flag==0)
    {
        printf("Element not found\n");
    }
    

}

void display()
{
    struct DLL*temp=first;

    if(first==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
          printf("%d->", temp->data);
          temp=(temp ->next); 
        } 
        while (temp!=NULL);
        printf("NULL\n");
        

    }
    
}
int main()
{
    insert_at_beginning(10);
    display();
    insert_at_beginning(20);
    display();
    insert_at_beginning(30);
    display();
    insert_at_end(40);
    display();
    insert_at_end(50);
    display();
    insert_at_end(60);
    display();
    insert_at_specific_position(70,2);
    display();
    insert_at_specific_position(80,5);
    display();
    deletion_at_beginning();
    display();
    deletion_at_end();
    display();
    deletion_at_specific_position(2);
    display();
    deletion_at_specific_position(3);
    display();
    search(70);
    display();
    search(100);
    display();

    
    return 0;
}