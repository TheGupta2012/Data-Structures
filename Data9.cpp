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
			void reverse(struct node* h)
			{
				if(last==NULL)
					{cout<<"No element.\nList as it is...";
				    }
				else
				{
					struct node* prev;
					struct node* curr;
					struct node* nex;
					prev=NULL;
					curr=head;
					nex=NULL;
					while(curr!=NULL)
					{	nex=curr->next;
						curr->next=prev;
						prev=curr;
						curr=nex;
					}
					head=prev;
					
					
				}
			}
		
};
int main()
{
	links link;
	cout<<"\n\t\t\t\tREVERSING A LINKED LIST WITHOUT DISTURBING ORDER....\n";
	cout<<"Enter the number of elements in the linked list:\n";
	int n,ele;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<":";
		cin>>ele;
		link.insert(ele);
	}
	cout<<"\nThe list is :";
	link.disp();
	cout<<"\nThe reversed list is :";
	link.reverse(head);
	link.disp();
return 0;
}
