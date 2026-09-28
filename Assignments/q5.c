#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning()
{
    int roll;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter roll number: ");
    scanf("%d", &roll);

    newNode->roll = roll;
    newNode->next = head;
    head = newNode;

    printf("Inserted at beginning\n");
}

void insertEnd()
{
    int roll;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter roll number: ");
    scanf("%d", &roll);

    newNode->roll = roll;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted at end\n");
}

void search()
{
    int roll;
    struct Node *temp = head;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while(temp != NULL)
    {
        if(temp->roll == roll)
        {
            printf("Roll number found\n");
            return;
        }

        temp = temp->next;
    }

    printf("Roll number not found\n");
}

void deleteRoll()
{
    int roll;
    struct Node *temp = head;
    struct Node *prev = NULL;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while(temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Roll number not found\n");
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Roll number deleted\n");
}

void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Student roll numbers: ");

    while(temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Search");
        printf("\n4. Delete");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteRoll();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}