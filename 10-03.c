#include <stdio.h>
#include <stdlib.h>
void enquee();
struct node{
    int priority, data;
    struct node *next;
}*new,*head,*temp,*ptr;
int count=0;
void enquee(){
    new = ( struct node* )malloc(sizeof(struct node));
    new-> next = NULL;
    if(new!=NULL)
    {
        head = new;
    }
    else 
    {
        if(head ->priority > new ->priority )
        {
            new->next=head;
            head=new;
        }
        else 
        {
            for(ptr=head; new->priority; ptr=ptr->next)
            {
                if(ptr -> next =NULL)
                {
                    ptr ->next = new;
                    temp =NULL;
                    break;
                }
                else
                {
                    temp =ptr;
                }
            }
            if(temp!=NULL)
            {
                new->next=ptr;
                temp->next=new;
                
            }
        }
    }
}






void insertend();
void display();
void deletebegin(){
    int n,choice=1;
    while(choice==1){
         printf("\nDeleting node in begin of List\n");
        if (new!=NULL)
        {
           
            temp=head;
            head=head->next;
            free(temp);
            printf("Deletion successfull\n");
            display();
            count--;

        }
        else
        printf("List is empty");

        printf("\nDo you want to delelte more nodes (1-)YES (2-)NO");
        scanf("%d",&choice);
    }
}
void deleteend(){
    int n,choice=1;
    while(choice==1){
         printf("\nDeleting node in end of List\n");
        if (new!=NULL)
        {
            for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
            //printf("%d %u",ptr->data,ptr->next);
            temp=ptr;
            for(ptr=head;ptr->next!=temp;ptr=ptr->next);
            ptr->next=NULL;
            free(temp);
            printf("Deletion successfull\n");
            display();
            count--;
        }
        else
        printf("List is empty");

        printf("\nDo you want to delete more nodes (1-)YES (2-)NO");
        scanf("%d",&choice);
    }
}

void insertbegin(){
    int n,choice=1;
    while(choice==1){
         printf("\nInserting node in begin of List\n");
        new=(struct node *)malloc(sizeof(struct node));
        if (new!=NULL)
        {
            printf("DMA successfull\n");
            printf("Enter the element:");
            scanf("%d",&n);
            new->data=n;
            temp=head;
            head=new;
            new->next=temp;
            count++;
        }
        else
        printf("DMA unsuccessfull");

        printf("Do you want to enter another node (1-)YES (2-)NO");
        scanf("%d",&choice);
    }
}
void display(){
    if(head==NULL)
    printf("List is empty");
    else{
        printf("The elements of DLL are:");
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        printf("%d ",ptr->data);
    }
}
void insertend(){
    int choice=1;
    while(choice==1){
        printf("inserting node in end of List\n");
        new=(struct node *)malloc(sizeof(struct node));
        if (new!=NULL)
        {
            printf("DMA successfull\n");
            int n;
            printf("Enter the data to be stored in node:");
            scanf("%d",&n);
            new->data=n;
            new->next=0;
            if(head==0)
                head=new;
            else{
                for(ptr=head;ptr->next!=0;ptr=ptr->next);
                ptr->next=new;
            }
            count++;
        }
        else
        printf("Memory Leak DMA unsuccessfull");

        printf("Do you want to enter another node (1-)YES (2-)NO");
        scanf("%d",&choice);
    }
}
void insertmiddle(){
    int choice=1;
    if(count>1){
    while(choice==1){
        printf("inserting node in middle of List\n");
        int pos;
                printf("Enter the position >1 and <=%d",count);
                scanf("%d",&pos);
        
        if (pos>1 && pos<=count)
        {
            new=(struct node *)malloc(sizeof(struct node));
            printf("DMA successfull\n");
            int n;
            printf("Enter the data to be stored in node:");
            scanf("%d",&n);
            new->data=n;
            new->next=0;
                ptr=head;
                for(int i=1;i<pos-1;i++)
                ptr=ptr->next;
                temp=ptr->next;
                ptr->next=new;
                new->next=temp;
                count++;
        }
        else
        printf("Entered wrong input\n");

        printf("Do you want to enter another node (1-)YES (2-)NO");
        scanf("%d",&choice);
    }
    }
    else
        printf("Enter more inputs");   

}

int main(){
    int ch=1;
    while(ch!=7){
    printf("\n1.Insert begin\n");
    printf("2.Insert end\n");
    printf("3.Insert middle\n");
    printf("4.Delete begin\n");
    printf("5.Delete end\n");
    printf("6.Display\n");
    printf("7.Exit\n");
    printf("Enter the choice what you want to do\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            insertbegin();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertmiddle();
            break;
        case 4:
            deletebegin();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            display();
            break;
        default:
            ch=7;
            printf("You have successfully come out of loop");
            break;
            
    }
    }
    return 0;
}