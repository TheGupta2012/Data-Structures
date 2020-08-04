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
			void swap_xy(int x,int y)
			{
				if(head == NULL)
				{
					cout<<"Empty list.\n";
					return ;
				}
				if(x<0 || y<0)
				{
					cout<<"Invalid Index\n";
					return;
				}
				else
				{
					node *t1=head;
					node *t2=head;
					while(x>0 && t1!=NULL)
						{t1=t1->next;
						x--;}
					while(y>0&& t2!=NULL)
					{
						t2=t2->next;
						y--;
					}
					if(t1==NULL || t2==NULL)
					{
						cout<<"Invalid index\nEnter again."<<endl;
						return ;
					}
					else
					{	cout<<"\nOriginal list\n";
						disp();
						int temp;
						temp = t1->data;
						t1->data = t2->data;
						t2->data = temp;
						cout<<"\nValues swapped.\n";
						disp();
					}
				}
			}
		
};
int main()
{
	links link;
	cout<<"\nIMPLEMENTING A LINKED LIST....\n";
	cout<<" Enter 1 for insertion.\n2 for display.\n 3 for swapping-1 for exit.\n";
	int n,x,y;
	
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
			case 2:cout<<"List is:";
					link.disp();
					break;
			case 3:cout<<"Enter x:";
				   cin>>x;
				   cout<<"\nEnter y:";
				   cin>>y;
				   link.swap_xy(x,y);
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
