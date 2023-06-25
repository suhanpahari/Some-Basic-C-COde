#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *new, *head, *tail, *ptr, *temp;

int count;

void dma();
void insertbegin();
void insertmid();
void insertend();
void displayforward();
void displayreverse();
void deletebegin();
void deletemid();
void deleteend();

int main()
{
    int choice1, choice2;
    while (1)
    {
        system("clear");
        printf("*** Link List Operations ***");
        printf("\n(1)Insert, (2)Delete, (3)Display forward, (4)Display backward (Any)Exit Application");
        printf("\nEnter choice: ");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            printf("\n\n**** Insertion Algorithms ****");
            printf("\n(1)Beginning, (2)End, (3)Middle, (Any) Exit Insert");
            printf("\nEnter choice: ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                insertbegin();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertmid();
                break;
            default:
                printf("\nExiting Insert operation\n");
            }
            break;
        case 2:
            printf("\n\n**** Deletion Algorithms ****");
            printf("\n(1)Beginning, (2)End, (3)Middle, (Any) Exit Delete");
            printf("\nEnter choice: ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                deletebegin();
                break;
            case 2:
                deleteend();
                break;
            case 3:
                deletemid();
                break;
            default:
                printf("\nExiting Delete operation\n");
            }
            break;
        case 3:
            displayforward();
            break;
        case 4:
            displayreverse();
            break;
        default:
        {
            printf("\nApplication Exit selected....Garbage Collection started....\n");
            int n = count;
            for (int i = 1; i <= n; i++)
                deletebegin();
            sleep(4);
            exit(0);
        }
        }
    }
    return 0;
}

void dma()
{
    new = (struct node *)malloc(sizeof(struct node));
    if (new != NULL)
    {
        new->prev = new->next = NULL;
        printf("\nEnter data: ");
        scanf("%d", &new->data);
    }
    else
        printf("\nDMA unsuccessful");
}

void insertbegin()
{
    dma();
    if (new != NULL)
    {
        if (head == NULL)
            head = tail = new;
        else
        {
            head->prev = new;
            new->next = head;
            head = new;
        }
        count++;
        printf("\nInsertion completed. List has %d node(s).\n", count);
        sleep(1);
    }
}

void insertmid()
{
    if (count > 1)
    {
        dma();
        if (new != NULL)
        {
            int pos, i;
            printf("\nEnter position >1 and <=%d : ", count);
            scanf("%d", &pos);

            if (pos > 1 && pos <= count)
            {
                for (ptr = head, i = 1; i < pos - 1; ptr = ptr->next, i++)
                    ;
                temp = ptr->next;
                ptr->next = new;
                new->prev = ptr;
                new->next = temp;
                temp->prev = new;
                count++;
                printf("\nInsertion completed. List has %d node(s).\n", count);
            }
            else
                printf("\nImproper input.");
        }
    }
    else
        printf("\nList has %d node(s). Try with insert begin/end options.\n", count);
    sleep(1);
}

void insertend()
{
    if (head != NULL)
    {
        dma();
        if (new != NULL)
        {
            tail->next = new;
            new->prev = tail;
            tail = new;
            count++;
            printf("\nInsertion completed. List has %d node(s).\n", count);
        }
    }
    sleep(1);
}

void displayforward()
{
    if (head == NULL)
        printf("\nList is Empty.\n");
    else
    {
        printf("\n%d element(s) of Linked list from head-end: ", count);
        for (ptr = head; ptr != NULL; ptr = ptr->next)
            printf("%d ", ptr->data);
        printf("\n");
    }
    sleep(3);
}

void displayreverse()
{
    if (tail == NULL)
        printf("\nList is Empty.\n");
    else
    {
        printf("\n%d element(s) of Linked list from tail-end: ", count);
        for (ptr = tail; tail != NULL; ptr = ptr->prev)
        {
            printf("%d ", ptr->data);
        }

        printf("\n");
    }
    sleep(2);
}

void deletebegin()
{
    if (head == NULL)
        printf("\nList is Empty.\n");
    else
    {
        printf("\nNode with data(%d) is deleted. ", head->data);
        if (count == 1)
        {
            free(head);
            head = tail = NULL;
        }
        else if (count > 1)
        {
            temp = head->next;
            temp->prev = NULL;
            free(head);
            head = temp;
        }
        count--;
        printf("\nList has %d node(s).\n", count);
    }
    sleep(1);
}

void deletemid()
{
    if (head == NULL)
        printf("\nList is Empty.\n");
    else if (count == 1)
        printf("\nList has 1 node. Try with delete begin option.\n");
    else if (count > 1)
    {
        int pos;
        printf("\nEnter node position >1 and <%d : ", count);
        scanf("%d", &pos);
        if (pos == 1)
            printf("\nTry with delete begin option.\n");
        else if (pos > 1 && pos < count)
        {
            int i;
            for (ptr = head, i = 1; i < pos - 1; ptr = ptr->next, i++)
                ;
            printf("\nNode-%d with data(%d) is deleted.\n", pos, ptr->next->data);
            temp = ptr->next->next;
            free(ptr->next);
            ptr->next = temp;
            temp->prev = ptr;
            count--;
            printf("\nList has %d node(s).\n", count);
        }
        else if (pos == count)
            printf("Try with delete end option.\n");
        else
            printf("\nImproper input.\n");
    }
    sleep(1);
}

void deleteend()
{
    if (head == NULL)
        printf("\nList is Empty.\n");
    else if (count == 1)
        printf("\nList has 1 node. Try with delete begin option.\n");
    else if (count > 1)
    {
        int i;
        for (ptr = head, i = 1; i < count - 1; ptr = ptr->next, i++)
            ;
        printf("\nNode-%d with data(%d) is deleted.\n", count, ptr->next->data);
        temp = ptr->next;
        ptr->next = NULL;
        tail = ptr;
        free(temp);
        count--;
        printf("\nList has %d node(s).\n", count);
    }
}