/* write combined all operation of circular doubly  linked list or doubly circular linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next,*prev;
}   *head,*tail,*temp;

void insert(int);   
void display();

int length=0;
void insert_at_any_position(int,int);
int update(int,int);
void Delete(int);
void reverse();
int main()
{
    int choice,data,position;
    head=tail=temp=NULL;
    while(1)
    {
		printf("\n****ENTER YOUR CHOICE****\n");
		printf("1:Insert ( add at last position)\n2:length of linked list\n3:insert at any position\n");
		printf("4:update\n");
		printf("5:delete\n6:reverse\n0:exit\n");
		scanf("%d",&choice);
	    switch(choice)
		 {
           case 1:printf("Data=");
		   scanf("%d",&data);
		   insert(data);
		   break;
          case 2:printf("length of linked list =%d\n",length);
		       break;

	        case 3:printf("position=");
		   scanf("%d",&position);
		   if(position<1 || position>length+1) 
		    {
			printf("\nYOUR POSITION IS WRONG!!!\n");
			break;
		    }
		   printf("data=");
		   scanf("%d",&data);
		   if(position==length+1)
			insert(data);
		   else
			insert_at_any_position(data,position);
           break;
	    case 4:printf("Position=");
		   scanf("%d",&position);
		   if(position<1 || position>length) 
		    {
			printf("\nYOUR POSITION IS WRONG!!!\n");
			break;
		    }
		   printf("data=");
		   scanf("%d",&data);
		   update(data,position);
		 
		   break;

		case 5:printf("position:");
		       scanf("%d",&position);
		       if(position<1 || position>length) 
		   {
			printf("\nYOUR POSITION IS WRONG!!!\n");
			break;
		   }
			   Delete(position);
			
			   break;
		case 6:reverse();
		       break;

	    case 0: return 0;  

	    default:printf("\n  SORRY YOUR CHOICE IS WRONG\n");
}
	display();
    }
}

void insert(int data)  
{
   temp=(struct node*)malloc(sizeof(struct node));    
  
   temp->data=data;

   if(head==NULL)
   {

	head=temp;
	tail=temp;
   }
   else
   {
       temp->next=tail->next;
       temp->prev=tail;
	    tail->next=temp;
	   tail=temp;

   }
  
   tail->next=head;
    head->prev=tail;
   length++;
}

void display()
{ 
	printf("\noriginal linked list are as follows in forward direction\n");
     for(temp=head;temp->next!=head;temp=temp->next)
	    printf("%d->",temp->data);
     printf("%d->",temp->data);
     printf("\b\b  ");
}


void insert_at_any_position(int data,int position)
{
    int i=1;
    struct node *new_node=NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if(position==1)
    {
		new_node->next=head;   
		new_node->prev=tail;   
		head->prev=new_node;
		head=new_node;
		tail->next=head;
	}
    else
    {
		for(temp=head;i<position-1;temp=temp->next,i++);
		new_node->next=temp->next;
		new_node->prev=temp;
		temp->next->prev=new_node;//newnode->next->prev=new_node;
		temp->next=new_node;
    }
    length++;
	printf("%d\n",tail->next->data);
	printf("%d\n",head->prev->data);
}

int update(int data,int position)
{
    int i=1;
    for(temp=head;i<position;temp=temp->next,i++);
    temp->data=data;

}
void Delete(int position) 
{
  int i=1;
  struct node *delete_node=NULL;
  if(position==1)      
  {
     delete_node=head;
     head=head->next;
     tail->next=head;
  }
  else 
  { 
     for(temp=head;temp->next!=head && i<position-1;temp=temp->next,i++);
     if(position==length) 
        tail=temp;
     delete_node=temp->next;
     temp->next=delete_node->next;
   
  }
  free(delete_node);
  length--;
}
void reverse()
{
	printf("linked list in backward direction\n");
   for(temp=tail;temp->prev!=tail;temp=temp->prev)
	    printf("%d<-",temp->data);
     printf("%d<-",temp->data);
     printf("\b\b  ");
}
