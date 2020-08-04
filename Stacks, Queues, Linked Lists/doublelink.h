//modifying file
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
typedef struct node nd;
nd* head;
nd* tail;
class links
{
	public://head=NULL;
		   //tail=NULL;
		   void insertN(int d)
		   { nd* temp;
		   	temp = new node;
		   	temp->data= d;
		   	temp->next=NULL;
		   	temp->prev=NULL;
		   	
		   	if(head==NULL)
		   		head=tail=temp;
		   	else
		   	{
		   		tail->next=temp;
		   		temp->prev=tail;
		   		tail=temp;
		   }
	       }
		   void insertAft(int d,int s)
		   {	nd* temp;
		   		nd* trv;
		   		if(head==NULL)
				   cout<<"\nEmpty list...";
				 else
				 {
				 	trv=head;
				 	while(trv->data!=s && trv->next!=NULL)
				 		trv=trv->next;
				 	if(trv->data!=s)
				 		cout<<"\nElement not found.";
				 	else
				 	{
				 		temp= new node;
				 		temp->data=d;
				 		temp->next=trv->next;
				 		trv->next=temp;
				 		if(trv->next!=NULL)
				 			trv->next->prev=temp;
				 		temp->prev=trv;
				 		tail=temp;
				 		
					 }
				  } 
		   }
		   void insertBef(int d, int s)
		   {
		   	nd* temp;
		   	nd* trv;
		   	if(head==NULL)
		   		cout<<"Empty list...";
		   	else
		   	{
		   		trv=head;
		   		while(trv->next!=NULL && trv->data!=s)
		   			trv=trv->next;
		   		if(trv->data!=s)
		   			cout<<"\nElement not found...";
		   		else
		   		{
		   			temp=new node;
		   			temp->data=d;
		   			temp->next=trv;
		   			temp->prev=trv->prev;
		   			if(trv!=head)
		   				trv->prev->next=temp;
		   			else
		   				head=temp;
					   
					trv->prev=temp;
				   }
			   }
		   }
		   void show()
		   {
		   	nd* temp;
		   	temp=head;
		   	if(head==NULL)
		   		cout<<"\nList is empty...";
		   	else
		   	{	cout<<"Your list is:\n";
		   	    cout<<"\nHead of linklist is:"<<head->data;
				   cout<<"\nTail of the linklist is:"<<tail->data<<"\n";
		   	    while(temp!=NULL)
				   {
				   cout<<temp->data<<"<-->";
				   temp=temp->next;}	
		    }
		   }
};
		   	
		   	
		   	

