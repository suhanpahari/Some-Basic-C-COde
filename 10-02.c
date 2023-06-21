#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *new, *head, *temp, *ptr;

int count;

void insertend()
{
    int choice = 1;
    while (choice == 1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        if (new != NULL)
        {
            printf("DMA is Successful\n");
            printf("Enter Data to be Store in new Node: ");
            scanf("%d", &new->data);
            new->next = NULL;
            if (head == NULL)
            {
                head = new;
            }
            else
            {
                for (ptr = head; ptr->next != NULL; ptr = ptr->next)
                    ;
                ptr->next = new;
            }
            count++;
            printf("LL Inserted, It has %d Element\n", count);
        }
        else
        {
            printf("DMA is Unsuccessful\n");
        }
        printf("Do you Want to Store another Node in the end of LL- 1-Yes or 2-No : ");
        scanf("%d", &choice);
    }
}

void insertbegin()
{
    int choice = 1;
    while (choice == 1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        if (new != NULL)
        {
            printf("\nDMA is Successful\n");
            printf("Enter Data to be Store in new Node: ");
            scanf("%d", &new->data);
            new->next = NULL;
            if (head == NULL)
            {
                head = new;
            }
            else
            {
                new->next = head;
                head = new;
            }
            count++;
            printf("LL Inserted, It has %d Element\n", count);
        }
        else
        {
            printf("DMA is Unsuccessful\n");
        }
        printf("Do you Want to Store another Node in the beginning of LL- 1-Yes or 2-No : ");
        scanf("%d", &choice);
    }
}

void insertmiddle()
{
    int pos, i;
    if (count > 1)
    {
        printf("\nEnter Position where you want to store new node in the middle of LL: ");
        scanf("%d", &pos);
        if (pos > 1 && pos <= count)
        {
            int choice = 1;
            while (choice == 1)
            {
                new = (struct node *)malloc(sizeof(struct node));
                if (new != NULL)
                {
                    printf("\nDMA is Successful\n");
                    printf("Enter Data to be Store in new Node: ");
                    scanf("%d", &new->data);
                    new->next = NULL;
                    if (head == NULL)
                    {
                        head = new;
                    }
                    else
                    {
                        for (ptr = head, i = 1; i < pos - 1; ptr = ptr->next, i++);
                        temp = ptr->next;
                        ptr->next = new;
                        new->next = temp;
                    }
                    count++;
                    printf("LL Inserted, It has %d Element\n", count);
                }
                else
                {
                    printf("DMA is Unsuccessful\n");
                }
                printf("Do you Want to Store another Node in the Middle of LL- 1-Yes or 2-No : ");
                scanf("%d", &choice);
            }
        }
        else
        {
            printf("This Not a Middle Position\n");
        }
    }
    else
    {
        printf("Insertion in Middle is Not Possible\n");
    }
}

void display()
{
    if (head == NULL)
    {
        printf("LL is Empty\n");
    }
    else
    {
        printf("%d Element of LL : ", count);
        for (ptr = head; ptr != NULL; ptr = ptr->next)
        {
            printf("%d ", ptr->data);
        }
    }
}

int main()
{
    insertend();
    display();
    insertbegin();
    display();
    insertmiddle();
    display();

return 0;
}