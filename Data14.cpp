#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
typedef struct node nd;
nd* top;
nd* head;
class st
{	
	public://top=NULL;
			//head=NULL;
		void push(int item)
		{
			nd* temp;
			temp=new node;
			temp->data=item;
			temp->next=NULL;
			if(top==NULL)
				{top=temp;
				head=top;}
			else
			{top->next=temp;
			top=temp;}
		}
		void pop()
		{
			if(top==NULL)
				cout<<"Stack underflow...";
			else
			{	int dat=top->data;
				nd* temp;
				temp=head;
                //important point...			
				if(temp==top)
					{top=NULL;
					 head=NULL;
				     }
				
				else
				{ while (temp->next!=top)
					temp=temp->next;
				  top=temp;
				  //important point...
				  top->next=NULL;
				  
			}
			}
	    }
		void disp()
		{
			if(top==NULL)
				cout<<"Empty stack.";
			else
			{	cout<<"\nStack is:";
				nd* temp;
				temp=head;
				while(temp!=NULL)
					{cout<<temp->data<<":";
					temp=temp->next;}
				cout<<"Top data:"<<top->data;
				
			}
		}
		};
int main()
{
	st s;
	int choice,ele;
	cout<<"\nSTACK USING LINKED LIST";
	cout<<"\nPress (1) for pushing\n(2) for popping\n(3) Display the stack\n(-1) to exit";
	while(true)
	{
		cout<<"\nEnter choice:";
		cin>>choice;
		if(choice==-1) break;
		else
		{
			if(choice==1)
			{
				cout<<"\nEnter the element:";
				cin>>ele;
				s.push(ele);
			}
			if(choice==2)
			{
				s.pop();
				cout<<"\nElement popped.";
				cout<<"\nUpdated list is :";
				s.disp();
			}
			if(choice==3)
			{
				s.disp();
			}
		}
	}
	return 0;
	
}
