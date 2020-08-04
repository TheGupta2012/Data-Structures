#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
	int temp;
	temp= *a;
	*a = *b;
	*b = temp;
	
}
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
			void reverseSq(struct node* h)
			{
				if(h==NULL)
					cout<<"No list to reverse.";
				else
				{
					node* tempb;
					node* tempf;
					node* temp;
					tempb=head;
					
					temp=head;
					int size=1;
					while(temp->next!=NULL)
						{temp=temp->next;
						size++;}
					int i,j;
					i=0;
					while(i<size/2)
					{	j=0;
						tempf=head;
						while(j<size-i-1)
							{tempf=tempf->next;
							j++;}
						swap( &tempb->data, &tempf->data);
						tempb=tempb->next;
						i++;
					}
				}
			}
};
int main()
{
	links link;
	cout<<"\n\t\t\t\t\tREVERSING A LINKED LIST ....\n";
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
	link.reverseSq(head);
	link.disp();
return 0;
}
