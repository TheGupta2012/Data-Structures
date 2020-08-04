#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
struct node* last=NULL;
class links
{
	public: 
			void insert (int n)
			{	struct node* temp;
				temp=new node;
				temp->data=n;
				//inserting at the end
				temp->next=NULL;
				if(last==NULL)
					{ last=temp;
					  head=last;
					}
				else
				{
					last->next=temp;
					last=temp;
				}		
			}
		//deleting last element
		// this code is giving error if I delete all the elements and then try to insert some other element on the list...
		int del(int ele)
		{
			if(last==NULL )
				return -1;
			else
			{
				struct node* temp;
				struct node* tempb;
				temp=head;
				tempb=head;
				while(temp!=last && temp->data!=ele)
					{tempb=temp;
					temp=temp->next;
			        }
			    if(temp->data!=ele)
			    	return -1;
			    else
			    {
			    	if(temp==tempb)
			    		{
			    			head=temp->next;
			    			if(head==NULL)
			    				last==NULL;
			    			return (ele);
						}
					else
					{	
						tempb->next=temp->next;
						if(temp->next==NULL)
							last=tempb;
					
						return (ele);
					}
				}
			}
		}
			void disp()
			{
				if(last==NULL)
					cout<<"Empty list.";
				else
				{
					struct node* temp;
					temp=head;
					while(temp!=NULL)
					{
						cout<<temp->data<<" ";
						temp=temp->next;
					}
					cout<<endl;
				}
			}
		
};
int main()
{
	links link;
	cout<<"\nIMPLEMENTING A LINKED LIST....\n";
	cout<<" CHOICES\n1 for insertion.\n2 for deletion \n3 for display.\n -1 for exit.\n";
	int n;
	
	while(true)
	{cout<<"\nChoice"; 
	cin>>n; 
	 if(n!=-1)
		{
		switch(n)
		{
			case 1: int a;
					cout<<"Enter element:";
					cin>>a;
					link.insert(a);
					cout<<"\nInserted...";
					break;
			case 2: int r;
					cout<<"\nEnter element you want to delete:";
					cin>>r;
					int b;
					b = link.del(r);
					if(b!=-1)
						cout<<r<<" was deleted.";
					else
						cout<<"\nElement not found.";
					break;
			case 3:cout<<"List is:";
					link.disp();
					break;
			default: break;
				
		}
	}
	else
	{ cout<<"Okay..";
	  break;
	}
}
return 0;
}
