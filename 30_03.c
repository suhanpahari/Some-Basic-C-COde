#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}; //*new, *head, *temp, *ptr;

//count
void count_of_nodes(struct node *head){
    int count = 0;
    if(head==NULL){
        printf("LLinked list is empty");
    }
    struct node *ptr =NULL;
    ptr = head;
    while(ptr !=NULL){
        count++;
        ptr = ptr->next;

    }
    printf("%d", count);
}

//display
void print_data(struct node *head){
    if(head == NULL){
        printf("ll is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d", ptr-> data);
        ptr = ptr ->next;
    }
}

//add end
add_at_end(struct node *head, int data){
    struct node *ptr,*temp;
    ptr = NULL;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;
    while(ptr->next !=NULL){
        ptr = ptr->next;
    }

}



//add beg
struct node* add_beg(struct node **head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 24;
    ptr ->next = NULL;

    ptr -> next = *head;;
    *head = ptr;
}


int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr ->data =98;
    ptr ->next = NULL;
    head->next->next = ptr;

    ptr = malloc(sizeof(struct node));
    ptr ->data= 3;
    ptr ->next = NULL;
    
    
    count_ofnodes(head);
    print_data(head);
    head = add_beg(&head, 23);
    ptr = head;
    while(ptr !=NULL)
    {
        printf("%d", ptr ->data);
        ptr = ptr ->next;
    }






    return 0;
}

