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
		void insert(int item)
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
		int del()
		{
			if(top==NULL)
				return -1;
			else
			{	int dat=top->data;
				nd* temp;
				temp=head;
                //important point...			
				if(temp==top)
					{top=NULL;
					 head=NULL;
				     return dat;}
				
				else
				{ while (temp->next!=top)
					temp=temp->next;
				  top=temp;
				  //important point...
				  top->next=NULL;
				  return dat;
			}
			}
	    }
		void disp()
		{
			if(top==NULL)
				cout<<"Empty list.";
			else
			{
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
	st stack;
	cout<<"STACK\nInsert element-(1)\nDelete element-(2)\nView stack-(3)\nExit-(-1)";
	int choice,it;
	while (true)
	{	cout<<"\nEnter choice:";
		cin>>choice;
		if(choice!=-1)
		{
			switch(choice)
			{
				case 1: cout<<"Enter item:";
						cin>>it;
						stack.insert(it);
						break;
				case 2: int b;
						b = stack.del();
						if(b!=-1)
							{cout<<"Element deleted.\nUpdated stack:";
							stack.disp();}
						else
							cout<<"\nStack underflow";
						break;
				case 3: cout<<"Stack is:";
						stack.disp();
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

