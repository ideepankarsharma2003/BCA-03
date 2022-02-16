#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 50

int queue[max];
int front = -1;
int rear = -1;

// insertion
void insertion(int num)
{
    if (rear == max-1)
    {
        printf("\nQueue is full !!!!\n\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        rear++;
        front++;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}

// deletion
void deletion()
{
    if (front == -1)
    {
        printf("\nQueue is already empty !!!!\n");
        return;
    }
    else
    {
        int temp = queue[front];
        front++;
        printf("\nElement deleted is %d\n", temp);
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