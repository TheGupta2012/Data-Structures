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
		   	{	cout<<"\n";
		   	    cout<<"\nHead of linklist is:"<<head->data;
				   cout<<"\nTail of the linklist is:"<<tail->data<<"\n";
		   	    while(temp!=NULL)
				   {
				   cout<<temp->data<<"<-->";
				   temp=temp->next;}	
		    }
		   }
};
		   	
		   	


int main()
{
		links ob;
	cout<<"DOUBLYLINKEDLIST\nInsert element at end-(1)\nInsert element after a certain element-(2)\nINsert element before a certain element-(3)\nView list-(4)\nExit-(-1)";
	int choice,it,ele;
	while (true)
	{	cout<<"\nEnter choice:";
		cin>>choice;
		if(choice!=-1)
		{
			switch(choice)
			{
				case 1: cout<<"Enter item:";
						cin>>it;
						ob.insertN(it);
						break;
				case 2: cout<<"Enter element after which you want to insert:";
						cin>>ele;
						cout<<"Enter item to insert:";
						cin>>it;
						ob.insertAft(it,ele);
						break;
				case 3: cout<<"Enter element before which you want to insert:";
						cin>>ele;
						cout<<"Enter item to insert:";
						cin>>it;
						ob.insertBef(it,ele);
				case 4: cout<<"List is:";
						ob.show();
						break;
				default: cout<<"invalid enter again.";	
				}
		}
		else
		{
			cout<<"Okay.";
			break;
		}
	}
	return 0;
}
