#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node * next;
};
struct node* head;
struct node* tail;
class deq
{
	public: void insertB(int data)
				{
					node* temp;
					temp=new node;
					temp->data= data;
					if(head==NULL)
						{
						temp->next=NULL;
						head=tail=temp;}
					else
					{
						temp->next=head;
						head=temp;
					}
				}
				
			void insertE(int data)
			{
				node* temp;
				temp=new node;
				temp->data=data;
				temp->next=NULL;
				if(head==NULL)
					head=tail=temp;
				else
				{
					tail->next=temp;
					tail=temp;
				}
			}
			void disp()
			{
				if(head==NULL)
					cout<<"No data to display...";
				else
				{
					node* temp;
					temp=head;
					cout<<"\nList is:";
					while (temp!=NULL)
						{cout<<temp->data<<"->";
						temp=temp->next;}
					cout<<"\nHead is:"<<head->data;
					cout<<"\nTail is:"<<tail->data;
				}
			}
			int delE()
			{
				if(head==NULL)
					return -1;
				else
				{	int d=tail->data;
					node* temp;
					temp=head;
					while(temp->next!=tail)
						temp=temp->next;
					node* tempb=tail;
					//important |v|
					temp->next=NULL;
					tail=temp;
					delete(tempb);
					return d;
					
				}
			}
			int delB()
			{
				if(head==NULL)
					return -1;
					else
					{
						int dat= head->data;
						node* temp;
						temp=head;
						head=head->next;
						delete(temp);		
						return dat;
					}
			}
};
int main()
{
	deq ob;
	cout<<"\n\t\t\t\t\t DOUBLE ENDED QUEUE USING A LINKED LIST.";
	cout<<"\nOperations-> \n1.Insert at beginning\n2.Insert at the end\n3.Delete from the beginning\n4.Delete from the end\n5.Display queue\n(-1) to exit.";
	int choice;
	while(true)
	{
		cout<<"\nEnter the choice:";
		cin>>choice;
		if(choice==-1) break;
		else
		{
			switch (choice)
			{
				case(1):{ int ele;
						cout<<"Enter the element:";
						cin>>ele;
						ob.insertB(ele);
					break;
				}
				case(2):{ int elem;
						cout<<"Enter the element:";
						cin>>elem;
						ob.insertE(elem);
					break;
				}
				case(3):{ int ele=ob.delB();
						cout<<endl<<ele<<" deleted from beginning.";
					break;
				}
				case(4):{ int ele=ob.delE();
						cout<<endl<<ele<<" deleted from the end.";
					break;
				}
				case(5):{	ob.disp();
					break;
				}
				default:{
					break;
				}
			}
		}
	}
	
	return 0;
}
