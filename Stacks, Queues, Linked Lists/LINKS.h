#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void swap(int* a,int* b)
{
	int temp;
	temp= *a;
	*a = *b;
	*b = temp;
	
}
class links
{
	public: struct node* head=NULL;
			struct node* last=NULL;
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
			    			delete tempb
			    			return (temp->data);
						}
					else
					{
						tempb->next=temp->next;
						temp=NULL;
						delete tempb;
						return (ele);
					}
				}
			}
		}
			void disp(struct node* h)
			{
				if(last==NULL)
					cout<<"Empty list.";
				else
				{
					struct node* temp;
					temp=h;
					while(temp!=NULL)
					{
						cout<<temp->data<<":";
						temp=temp->next;
					}
					cout<<endl;
				}
			}
			//O(n) algo
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
			//O(n^2) algo
			void reverseSq(struct node* h)
			{
				if(h==NULL)
					cout<<"No list to reverse.";
				else
				{
					node* tempb, tempf, temp;
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
