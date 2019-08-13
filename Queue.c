//creating the queue and reverse the first k elements of queue

#include<stdio.h>
#include<malloc.h>

struct queuenode 
{
	int data;
	struct queuenode * next;

};
typedef struct queuenode node;
node *start=NULL,*end=NULL;
void enQueue(int data)
{
	node * newnode;
	newnode=(node *)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->data=data;
	if(start==NULL)
	{
		start=newnode;
		end=newnode;

	}
	else
	{
		end->next=newnode;
		end=newnode;

	}
}
void display()
{
	node * temp=start;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}

}
void reverse(int k)
{
	node * temp,*temp1,*temp2;
	temp=start;
	temp1=start->next;
	if(k==1)
	return;
	while(k>1)
	{
		if(temp1!=NULL)
		{
			temp2=temp1->next;
			temp1->next=temp;
			temp=temp1;
			temp1=temp2;
			k--;
		}
		else 
		break;

	}
	start->next=temp2;
	start=temp;

}
void main()
{
	int data;
	printf("Enter queue element Enter -1 to terminate\n");
	while(1)
	{
		scanf("%d",&data);
		if(data==-1)
		break;
		else
		enQueue(data);
	}
	display();
	printf("\nEnter value k-");
	scanf("%d",&data);
	reverse(data);
	display();
}
