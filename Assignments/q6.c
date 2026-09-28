#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void insert()
{
    char page[50];
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter page name: ");
    scanf("%s", page);

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        current = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Page inserted\n");
}

void forward()
{
    if(current == NULL)
    {
        printf("No pages available\n");
    }
    else if(current->next == NULL)
    {
        printf("Already at last page\n");
    }
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

void backward()
{
    if(current == NULL)
    {
        printf("No pages available\n");
    }
    else if(current->prev == NULL)
    {
        printf("Already at first page\n");
    }
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

void deletePage()
{
    char page[50];
    struct Node *temp = head;

    printf("Enter page to delete: ");
    scanf("%s", page);

    while(temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Page not found\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(current == temp)
    {
        if(temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page deleted\n");
}

void displayForward()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    printf("Pages first-to-last: ");

    while(temp != NULL)
    {
        printf("%s ", temp->page);
        temp = temp->next;
    }

    printf("\n");
}

void displayBackward()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("No pages available\n");
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    printf("Pages last-to-first: ");

    while(temp != NULL)
    {
        printf("%s ", temp->page);
        temp = temp->prev;
    }

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Insert Page");
        printf("\n2. Move Forward");
        printf("\n3. Move Backward");
        printf("\n4. Delete Page");
        printf("\n5. Display First-to-Last");
        printf("\n6. Display Last-to-First");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                forward();
                break;

            case 3:
                backward();
                break;

            case 4:
                deletePage();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}