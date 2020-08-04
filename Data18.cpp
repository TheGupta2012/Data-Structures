#include<bits/stdc++.h>
using namespace std;
struct node
{
	int info;
	int priority;
	node *next;
	node *prev;
};

void insert(node **front,node **rear,int data, int p)
{
	node *temp=new node;
	temp->info=data;
	temp->priority=p;
	temp->next=temp->prev=NULL;
	if(*front==NULL)
		{ *front=*rear=temp;
		}
	else
	{
		if(p<= (*front)->priority)
		{
			temp->next=(*front);
			(*front)->prev=temp;
			(*front)=temp;
		}
		else if(p>= (*rear)->priority)
		{
			(*rear)->next=temp;
			temp->prev=(*rear);
			(*rear)=temp;
		}
		else
		{
			node *t=(*front);
			while(t->priority <= p)
				t=t->next;
			temp->prev=t->prev;
			temp->next=t;
			t->prev->next=temp;
			t->prev=temp;	
		}
	}
}
int peek(node **front, node **rear)
{
	if(*rear==NULL)
		return -1;
	else
		return ((*rear)->info);
}
int retMaxpriority(node **front,node **rear)
{
	if(*rear==NULL)	return -1;
	else
	{ 
		int dat= (*rear)->info;
		node *temp=*rear;
		(*rear)=(*rear)->prev;
		(*rear)->next=NULL;
		delete(temp);
		return(dat);
	}
}
void show(node **front, node **rear)
{
	if((*rear)==NULL)
		cout<<"\nEmpty queue.";
	else
	{	cout<<"\nThe queue is:";
		node *temp= (*front);
		while(temp!=NULL)
		{
			cout<<"\nData :"<<temp->info<<", Priority :"<<temp->priority;
			temp=temp->next;
		}
	}
}
int main()
{
	node *front=NULL;
	node *rear=NULL;
	cout<<"\n\t\t\tImplementing Priority Queue using a linked list.";
	cout<<"\nCHOICES\n 1. Insert element\n 2. Look at maximum priority element\n 3. Delete maximum priority element\n 4. Show queue\n (-1) for exit";
	int choice,elem,p;
	while(1)
	{
		cout<<"\nEnter choice:";
		cin>>choice;
		if(choice==-1)
			break;
		switch (choice)
		{
			case 1:{ cout<<"Enter the element :";
					 cin>>elem;
					 cout<<"Enter the priority :";
					 cin>>p;
					 insert(&front,&rear,elem,p);
				break;
			}
			case 2:{ cout<<"The maximum priority element is:";
					cout<<peek(&front,&rear);
				break;
			}
			case 3:{
				cout<<"The maximum priority element is:";
				cout<<retMaxpriority(&front,&rear);
				cout<<"\nQueue updated.";
				break;
			}
			case 4:{
				cout<<"Queue is:";
				show(&front,&rear);
				break;
			}
		}
	}
	return 0;
}

