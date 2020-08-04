
#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node* next;
};
typedef struct node nd;
nd* rear;
nd* front;
class Q
{
	public: void insert(int item)
	        {
	        	nd* temp;
	        	temp=new node;
	        	temp->data=item;
	        	temp->next=NULL;
	        	//important...if you check the condition that rear == front then it will give an error why?
	        	//as when you have inserted the first element , you still would have front==rear and not
	        	//just in the emty queue case...
				if(rear==NULL)
	        		{rear=temp;
	        		front=rear;}
	        	else
	        	{
	        		rear->next=temp;
	        		rear=temp;
				}
			}
			int del()
			{
				if(front==NULL)
					return -1;
				else
				{
					int dat=front->data;
					if(front==rear)
						{front=NULL;
						rear=NULL;
						return dat;}
					else
					{
						front=front->next;
						return dat;
					}
				}
			}
			void disp()
			{
				if(front==NULL)
					cout<<"\nEmpty queue...";
				else
				{
					nd* temp;
					temp=front;
					cout<<"\nFront element:"<<front->data;
					cout<<"\nRear element:"<<rear->data;
					cout<<"\nList:";
					while(temp!=NULL)
						{cout<<temp->data<<":";
						temp=temp->next;}
				}
			}
};

