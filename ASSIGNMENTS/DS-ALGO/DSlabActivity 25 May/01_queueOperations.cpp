#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int queue[50];
int front = -1;
int rear = -1;

// insertion
void insertion(int item)
{
    if(rear<49)
    {
        if(front==-1)
            front++;
        
        rear++;
        queue[rear]=item;
    }

    else
        printf("\nThe queue is full !!!!");
}

// deletion
void deletion()
{
    int item;
    if (front != -1)
    {
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }

        else
            front++;

        printf("\nNumber deleted is %d\n", item);
    }
    else
    {
        printf("\nQueue is already empty !!!!\n");
    }
}

// display
void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty !!!!\n");
        return;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("\n%d", queue[i]);
        }
        printf("\n");
    }
}

// peek
void peek()
{
    if (front == -1)
    {
        printf("\nQueue is empty !!!!\n");
        return;
    }
    else
    {
        printf("\n%d\n", queue[front]);
    }
}

int main()
{
    char ch[5] = "yes";
    do
    {
        int choice;
        printf("\nSelect your choice:\n1.Insertion\n2.Deletion\n3.Display\n4.Peek\n5.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int num;
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            insertion(num);
            break;

        case 2:
            deletion();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            printf("\nTerminating the program !!!");
            exit(1);
            break;

        default:
            printf("Wrong choice !!!!!!!!!\n");
        }

        printf("\n\nDo you want to continue(yes/no):   ");
        fflush(stdin);
        gets(ch);

    } while (strcmp(ch, "yes") == 0);

    return 0;
}