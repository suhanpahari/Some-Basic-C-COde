#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*new, *head, *temp, *ptr;
int count;
void frequency()
{
    int val=0, num, freq=0, j=0, arr[count];
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        num=ptr->data;
        for(int i=0;i<count;i++)
        {
            if(num==arr[i])
            {
                val=1;
                break;
            }
            else
                val=0;
        }
        if(val==1)
            continue;
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            if(num==temp->data)
                freq++;
        }
        printf("Frequency of %d is %d\n",num,freq);
        freq=0;
        arr[j]=num;
        j++;
    }
}
void insertbegin()
{
    new=(struct node *)malloc(sizeof(struct node));
    if(new!=NULL)
    {
        printf("DMA successfull\n");
        printf("Enter the element here:");
        scanf("%d",&new->data);
        new->next=head;
        head=new;
        count++;
        printf("Successfull inserted. LL has %d elements\n",count);
    }
    else printf("DMA unsuccessfull\n");
}
void insertend()
{
    new=(struct node *)malloc(sizeof(struct node));
    if(new!=NULL)
    {
        printf("DMA successfull\n");
        printf("Enter the element here:");
        scanf("%d",&new->data);
        new->next=NULL;
        for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
        ptr->next=new;
        count++;
        printf("Successfull inserted. LL has %d elements\n",count);
    }
    else printf("DMA unsuccessfull\n");
}
void display()
{
    if(count<1)
        printf("LL is empty\n");
    else{
        printf("Elements in LL are:");
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
            printf("%d ",ptr->data);
        printf("\n");}
}
int main()
{
    new=(struct node *)malloc(sizeof(struct node));
    if(new!=NULL)
    {
        printf("DMA successfull\n");
        printf("Enter the element here:");
        scanf("%d",&new->data);
        head=new;
        head->next=NULL;
        count++;
        printf("Element inserted successfully. LL has %d elements\n",count);
        int choice=1;
        while(0<choice<6)
        {
            printf("Choose from the menu:\n1. Insert at the beginning\n2. Insert at the end\n3. Display\n");
            printf("4. Check Frequency of each element\n5. Exit\nEnter the choice here:");
            scanf("%d",&choice);
            while(choice<0 || choice>5)
            {
                printf("Enter the correct choice:");
                scanf("%d",&choice);
            }
            switch(choice)
            {
                case 1:insertbegin();
                break;
                case 2:insertend();
                break;
                case 3:display();
                break;
                case 4:frequency();
                break;
            }
            if(choice==5)
                break;
        }        
    }
    else printf("DMA unsuccessfull");
}