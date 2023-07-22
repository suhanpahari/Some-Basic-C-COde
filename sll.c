#include<stdio.h>		//printf(), scanf()
#include<stdlib.h>	//malloc(), free(), exit()
#include<unistd.h>	//sleep()
struct node								//Mem. req. of each node in LL
{
	int data;
	struct node *next;
}*new, *head, *ptr, *temp;			//each pointer has a certain purpose

int count;								//Size of LL (tot. no. of nodes)

void dma();								//perform DMA with malloc(), gets node contents
void insertbegin();
void insertmid();
void insertend();
void display();
void deletebegin();
void deletemid();
void deleteend();

int main()
{
	int choice1, choice2;
	while(1)							//Dynamic Growth/Shrinking of LL
	{
		system("clear");
		printf("********* Link List Operations *********");
		printf("\n(1)Insert, (2)Delete, (3)Display, (4)Exit");
		printf("\nEnter choice: ");
		scanf("%d", &choice1);
		switch(choice1)
		{
			case 1: 
				printf("\n********* Insertion Algorithms *********");
				printf("\n(1)Beginning, (2)End, (3)Middle, (Any) Exit Insert");
				printf("\nEnter choice: ");
				scanf("%d", &choice2);
				switch(choice2)
				{
					case 1: insertbegin(); break;
					case 2: insertend(); break;
					case 3: insertmid(); break;
					default: printf("\nExiting Insert operation\n");					
				}
				break;
			case 2:
				printf("\n********* Deletion Algorithms *********");
				printf("\n(1)Beginning, (2)End, (3)Middle, (Any)Exit Delete");
				printf("\nEnter choice: ");
				scanf("%d", &choice2);
				switch(choice2)
				{
					case 1: deletebegin(); break;
					case 2: deleteend(); break;
					case 3: deletemid(); break;
					default: printf("\nExiting Delete operation\n");					
				}
				break;
			case 3:
				display(); 
				break;
			case 4:
				printf("\nApplication exit selected .... Garbage collection started....\n"); 
				int n = count;
				for(int i=1; i<=n; i++)
					deletebegin();
				sleep(2);
				exit(0);
			default: 
				printf("\nWrong Choice. Try again.\n");
		}	
	}
	return 0;
}

void dma()
{
	new = (struct node*)malloc(sizeof(struct node));
	if(new!=NULL)
	{
		printf("\nEnter data: ");
		scanf("%d", &new->data);
		new->next = NULL;
	}
	else
		printf("\nDMA unsuccessful\n");
}

void insertbegin() 									
{
	dma();												
	if(new!=NULL)										
	{
		if(head==NULL) 			//Inserting 1st node								
			head=new;
		else							//Inserting Node-2 onwards						
		{
			new->next = head;									
			head = new;											
		}
		count++;													
		printf("\nInsertion completed. List has %d node(s).\n", count);
	}
	sleep(1);
}

void insertmid() 
{
	if(count>1)										
	{									
		dma();										
		if(new!=NULL)
		{
			int pos, i;								
			printf("\nEnter position >1 and <=%d : ", count);	
			scanf("%d", &pos);
			
			if(pos>1 && pos<=count)										
			{
				for(ptr=head, i=1; i<pos-1; ptr=ptr->next, i++);
				temp = ptr->next;											
				ptr->next = new;											
				new->next = temp;											
				count++;														
				printf("\nInsertion completed. List has %d node(s).\n", count);
			}
			else printf("\nImproper input.\n");						
		}
	}
	else printf("\nList has %d node(s). Try with insert begin/end options.\n", count);
	sleep(1); 
}															

void insertend() 
{
	if(head!=NULL)
	{
		dma();
		if(new!=NULL)
		{
			for(ptr=head; ptr->next!=NULL; ptr=ptr->next);
			ptr->next = new;
	
			count++;
			printf("\nInsertion completed. List has %d node(s).\n", count);
		}
		sleep(1);
	}
	else printf("\nTry Insert begin.\n");
}

void display() 
{
	if(head==NULL)
		printf("\nList is Empty\n");
	else
	{
		printf("\n%d element(s) in Linked list: ", count);
		for(ptr=head; ptr!=NULL; ptr=ptr->next)
			printf("%d ", ptr->data);
		printf("\n");
	}
	sleep(3);
}

void deletebegin() 
{
	if(head==NULL)
		printf("\nList is Empty\n");
	else if(count==1)
	{
		printf("\nNode with data(%d) is deleted. ", head->data);
		free(head);
		head = NULL;
		count--;
		printf("List has %d node(s).\n", count);
	}
	else if(count>1)
	{
		printf("\nNode with data(%d) is deleted. ", head->data);
		temp = head->next;
		free(head);
		head = temp;
		count--;
		printf("List has %d node(s).\n", count);
	}
	sleep(1);
}

void deletemid() 
{
	if(head==NULL)
		printf("\nList is Empty\n");
	else if(count==1) 
		printf("\nList has 1 node. Try with delete begin option.\n");
	else if(count>1)
	{
		int pos;
		printf("\nEnter node position >1 and <%d : ", count);
		scanf("%d", &pos);
		if(pos==1) 
			printf("\nTry with delete begin option.\n");
		else if(pos>1 && pos<count)
		{ 
			int i;		
			for(ptr=head, i=1; i<pos-1; ptr=ptr->next, i++);
			printf("\nNode-%d with data(%d) is deleted. ", pos, ptr->next->data);
			temp = ptr->next->next;
			free(ptr->next);
			ptr->next = temp;
			count--;
			printf("List has %d node(s).\n", count);
		}
		else if(pos==count) 
			printf("\nTry with delete end option.\n");
		else printf("\nImproper input.\n");
	}
	sleep(1);	
}

void deleteend() 
{
	if(head==NULL)
		printf("\nList is Empty.\n");
	else if(count==1)
		printf("\nList has 1 node. Try with delete begin option.\n");
	else if(count>1)
	{
		int i;
		for(ptr=head, i=1; i<count-1; ptr=ptr->next, i++);
		printf("\nNode-%d with data(%d) is deleted. ", count, ptr->next->data);
		temp = ptr->next;
		ptr->next = NULL;
		free(temp);
		count--;
		printf("List has %d node(s).\n", count);
	}
	sleep(1);	
}
