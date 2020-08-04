#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class links
{	node *head;
	node *tail;
	public: 
			void insert(int data)
			{	node *temp=new node;
				temp->data=data;
				if(head==NULL)
					head=tail=temp;
				else
					{tail->next=temp;
					tail=temp;}				
			}
			node *gethead()
			{
				return this->head;
			}
			node *gettail ()
			{
				return this->tail;
			}
			void display()
			{
				if(head==NULL)
					cout<<"\nEmpty list.";
				else
				{
					node *temp;
					temp=head;
					cout<<"\nThe list is:"<<endl;
					while(temp!=NULL)
					{
						cout<<temp->data<<":";
						temp=temp->next;
					}
				}
			}
			
}
void merge(node *h1, node *h2)
{
	links merged;
	int m,n;
	m=0;
	n=0;
	node *temp1,temp2;
	temp1=h1;
	temp2=h2;
	while(temp1!=NULL)
		n++;
	while(temp2!=NULL)
		m++;
	node *ins1,ins2;
	ins1=h1;
	ins2=h2;
	if(m<=n)
	{
		while(ins1!=NUll)
			{	if(ins2!=NULL)
					{
						merged.insert(ins1->data);
						merged.insert(ins2->data);
						ins1=ins1->next;
						ins2=ins2->next;
					}
				else
					{
						merged.insert(ins1->data);
						ins1=ins1->next;
					}
	        }
	    }
	else
	{
		while(ins2!=NULL)
			{
				if(ins1!=NULL)
				{
					merged.insert(ins1->data);
					merged.insert(ins2->data);
					ins1=ins1->next;
					ins2=ins2->next;
				}
				else
				{
					merged.insert(ins2->data);
					ins2=ins2->next;
				}
			}
	}
	merged.display();
}













