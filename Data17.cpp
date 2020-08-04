#include<iostream>
#define MAX 6
using namespace std;
int front=0;
int rear=0;
int arr[MAX];
void ins(int d)
{
	if(front==((rear+1)%MAX))
		cout<<"Queue full.";
	else
	{
		arr[rear]=d;
		rear=(rear+1)%MAX;
	}
}
int del()
{
	if(front==rear)
		return -1;
	else
	{
		int temp;
		temp=arr[front];
		front=(front+1)%MAX;
		return temp;
	}
}
void disp()
{
	if(front==rear)
	{
		cout<<"Empty queue.";
	}
	else
	{	cout<<"\nCIRCULAR QUEUE IS:- ";
		if(rear>front)
		{for(int i=front;i<rear;i++)
			{ cout<<arr[i]<<" ";
			}
		}
		else
		{
		
		for(int i=front;i<MAX;i++)
		{
			cout<<arr[i]<<" ";
		}
		for(int i=0;i<rear;i++)
		{
			cout<<arr[i]<<" ";
		}
	}
}
}
int main()
{
	ios::sync_with_stdio(false);
	int choice;
	cout<<"\n\t\t\t\t\tCIRCULAR QUEUE USING AN ARRAY";
	cout<<"\nOPERATIONS->\n 1.Insert element\n 2.Delete from queue\n 3.Show queue\n 4.(-1) to exit.";
	while(1)
	{
		cout<<"\n Enter choice:";
		cin>>choice;
		if(choice==-1)	break;
		else
		{
			switch(choice)
			{
				case(1):{ int ele;
						cout<<"\nEnter the element:";
						cin>>ele;
						ins(ele);
					break;
				}
				case(2):{ int fr=del();
						 if(fr==-1) cout<<"Empty queue.";
						 else cout<<"\n"<<fr<<" was deleted.";
					break;
				}
				case (3):{ disp();
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








